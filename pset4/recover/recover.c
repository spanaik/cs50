#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if( argc != 2)
    {
        fprintf(stderr,"Usage: ./recover image");
        return 1;
    }

    FILE *inFile = fopen(argv[1],"r");
    if (!inFile)
    {
        fprintf(stderr,"File:%s not found",argv[1]);
        return 2;
    }

    int JpegChunk = 512;
    unsigned char bytes[JpegChunk];

    int count = 0;
    char Name[8] = "";
    FILE *outFile = NULL;

    while(fread(bytes, JpegChunk, 1, inFile) == 1)
    {
        if(bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && bytes[3] >= 0xe0 && bytes[3] <= 0xef)
        {
            if (outFile != NULL)
                fclose(outFile);
            sprintf(Name,"%03d.jpg",count);
            outFile = fopen(Name,"a");
            count++ ;
            fwrite(bytes, JpegChunk, 1, outFile);
        }
        else
        {
            if(outFile != NULL)
                fwrite(bytes, JpegChunk, 1, outFile);
        }
    }
    fclose(outFile);
}