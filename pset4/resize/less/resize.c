// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    int n = atoi(argv[1]);
    if (n > 100)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile, n cant be greater than 100\n");
        return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);


    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    //Modify biHeight & Width for OutFile
    BITMAPFILEHEADER bf_out = bf;
    BITMAPINFOHEADER bi_out = bi;
    bi_out.biWidth = bi_out.biWidth * n;
    bi_out.biHeight = bi_out.biHeight * n;

    int padding_out = (4 - (bi_out.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //Modify bfSize for OutFiles
    bf_out.bfSize = (((bi_out.biWidth) * abs(bi_out.biHeight)) * 3) + 54 + (padding_out * abs(bi_out.biHeight));
    bi_out.biSizeImage = ((bi_out.biWidth) * abs(bi_out.biHeight)) * 3 + (padding_out * abs(bi_out.biHeight));


    // write outfile's BITMAPFILEHEADER
    fwrite(&bf_out, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi_out, sizeof(BITMAPINFOHEADER), 1, outptr);

    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;


    //Array of RGPTRIPLE for OUT;
    RGBTRIPLE triple_out[bi_out.biWidth];
    int count = 0;
    int l = 0;
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        l = 0;
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;
            count = 0;
            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            while(count < n)
            {
                // write RGB triple to outfile
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                triple_out[l] = triple;
                count++;
                l++;
            }
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)

            for (int k = 0; k < padding_out; k++)
            {
              fputc(0x00, outptr);
            }


        count = 0;
        while(count < n - 1)
        {
            fwrite(&triple_out, sizeof(RGBTRIPLE) * bi_out.biWidth, 1, outptr);
            for (int k = 0; k < padding_out; k++)
            {
                fputc(0x00, outptr);
            }
            count++ ;
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}