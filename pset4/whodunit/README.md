# Questions

## What's `stdint.h`?

stdint.h is a header file in the C standard library introduced in the C99 standard library section 7.18 to allow programmers to write more portable code by providing a set of typedefs that specify exact-width integer types, together with the defined minimum and maximum allowable values for each type, using macros

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

This will give us different implementations of signed and unsigned integers i.e 8bits, 32bits & 16bits

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE = 1 Byte, DWORD = 4 Bytes, LONG = 5 Bytes, WORD = 2 Bytes

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

0x4d42

## What's the difference between `bfSize` and `biSize`?

bfSize = The size, in bytes, of the bitmap file
biSize = The number of bytes required by the structure i.e. 40 bytes

## What does it mean if `biHeight` is negative?

the bitmap is a top-down DIB and its origin is the upper-left corner

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If the In-File does not exist and if Out-File cant be created

## Why is the third argument to `fread` always `1` in our code?

Cause we want to read byte by byte

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

4

## What does `fseek` do?

Move the File Pointer by given number of bytes of the function call

## What is `SEEK_CUR`?

It moves file pointer position to given location

## Whodunit?

It was Professor Plum with the candlestick in the library