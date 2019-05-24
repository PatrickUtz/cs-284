/*
 * reverse-words.c
 * Author: Patrick Utz
 * Date: 04.04.2019
 * 
 * A C program that reverses words, in place, within a given string
 */

#include <string.h>
#include <stdio.h>

#include "reverse-range-in-place.h"
#include "reverse-words.h"

void reverse_words(char* string) {
    // allocate space and track spaces
    reverse_range_in_place(string, 0, strlen(string));
    int numSpaces = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == ' ') {
            numSpaces++; 
        }
    }
    int spaces[numSpaces];
    int spaceCount = 0;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == ' ') {
            spaces[spaceCount] = i;
            spaceCount++; 
        }
    }

    // reverse stuff 
    for (int i = 0; i < numSpaces-1; i++) {
        if (spaces[i+1] - spaces[i] > 1) {
            reverse_range_in_place(string, spaces[i]+1, spaces[i+1]-1);
        }
    }

    if (spaces[numSpaces-1] != (strlen(string)-1)) {
        reverse_range_in_place(string, spaces[numSpaces-1]+1, strlen(string)-1);
    }

    if (spaces[0] != 0) {
        reverse_range_in_place(string, 0, spaces[0]-1);
    }
    return;
}