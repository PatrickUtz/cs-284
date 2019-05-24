/*
 * interval.c
 * Author: Patrick Utz
 * Date: 03.26.2019
 * 
 * A C program that takes two command line arguments which are the names of 
 * two uppercase piano keys, assumes that the second key is higher than the first key, and writes 
 * to standard output the interval between those two keys.
 */

#include <stdio.h>
#include <string.h>

char *notes[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
char *intervals[] = {
    "minor second",
    "major second",
    "minor third",
    "major third",
    "perfect fourth",
    "tritone",
    "perfect fifth",
    "minor sixth",
    "major sixth",
    "minor seventh",
    "major seventh",
    "perfect octave"
};
int inNotes[2] = {-1, -1};

int checkInput(char** argv) {
    if (argv[1] == NULL || argv[3] != NULL) {
        printf("\nThis program requires exactly two command line arguments.\n\n");
        return -1;
    }
    for (int i = 0; i < 12; i++) {
        if (strcmp(notes[i], argv[1]) == 0) {
            inNotes[0] = i;
            break;
        } 
    }
    if (inNotes[0] == -1) {
        printf("\nNo such key: %s\n\n", argv[1]);
        return -1;
    }
    for (int i = 0; i < 12; i++) {
        if (strcmp(notes[i], argv[2]) == 0) {
            inNotes[1] = i;
            break;
        } 
    }
    if (inNotes[1] == -1) {
        printf("\nNo such key: %s\n\n", argv[2]);
        return -1;
    }
    return 1;
}

int howFar(int inNoteLow, int inNoteHigh) {
    int distance = inNoteHigh - inNoteLow;
    if (distance < 0) {
        distance = -distance;
    }
    return distance;
}

int main(int argc, char** argv) {
    if (checkInput(argv) == -1) {
        return 0;
    }
    int keysApart = howFar(inNotes[0], inNotes[1]);
    if (keysApart == 0) {
        keysApart = 12;
    }
    printf("\n%s to %s is a %s.\n\n", argv[1], argv[2], intervals[keysApart-1]);
    return 0;
}