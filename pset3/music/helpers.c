// Helper functions for music

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int num = fraction[0] - '0';
    int den = fraction[2] - '0';
    return round((num*8)/den);
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char letter;
    char number;
    char accidental;
    if (strlen(note)!=3)
    {
        letter = note[0];
        number = note[1] - '0';
        accidental = '?';
    }
    else
    {
        letter = note[0];
        number = note[2] - '0';
        accidental = note[1];
    }
    int n = 0;


    // ** A3 A#3 B3 C4 C#4 D4 D#4 E4 F4 F#4 G4 G#4 A4 A#4 B4 C5 C#5 D5 D#5 E5 F5 F#5 G5 G#5 A5 A#5 B5 **
    switch(accidental)
    {
        case '#':
                n+=1;
                break;
        case 'b':
                n-=1;
                break;
    }
    switch(letter)
    {
        case 'A':
                n+=0;
                break;
        case 'B':
                n+=2;
                break;
        case 'C':
                n-=9;
                break;
        case 'D':
                n-=7;
                break;
        case 'E':
                n-=5;
                break;
        case 'F':
                n-=4;
                break;
        case 'G':
                n-=2;
                break;
    }


    n += (number-4) * 12;
    return round(pow(2,(n/12.0)) * 440);
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s,"")==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
