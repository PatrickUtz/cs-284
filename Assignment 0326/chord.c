/*
 * chord.c
 * Author: Patrick Utz
 * Date: 03.26.2019
 * 
 * A C program that takes a command line argument which is the uppercase name 
 * of a piano key, and writes to standard output the major, minor, dominant 7th, and diminished 
 * 7th chords for that key.
 */

#include <stdio.h>
#include <string.h>

char *notes[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

int checkInput(char** argv) {
    if (argv[1] == NULL || argv[2] != NULL) {
        printf("\nThis program requires exactly one command line argument.\n\n");
        return -1;
    }
    for (int i = 0; i < 12; i++) {
        if (strcmp(notes[i], argv[1]) == 0) {
            return i;
        } 
    }
    printf("\nNo such key: %s\n\n", argv[1]);
    return -1;
}

int noteAddition(int inNote, int interval) {
    int outNote = inNote + interval;
    if ( outNote > 11 ) {
        outNote = outNote - 12;
    }
    return outNote;
}

int main(int argc, char** argv) {
    int index = checkInput(argv);
    if (index == -1) {
        return 0;
    }
    // major 
    int middleIndex = noteAddition(index, 4);
    printf("\n%s: %s %s %s\n", notes[index], notes[index], notes[middleIndex], notes[noteAddition(middleIndex, 3)]);

    // minor
    middleIndex = noteAddition(index, 3);
    printf("%sm: %s %s %s\n", notes[index], notes[index], notes[middleIndex], notes[noteAddition(middleIndex, 4)]);

    // dominant 7th 
    int middleIndexL = noteAddition(index, 4);
    int middleIndexR = noteAddition(middleIndexL, 3);
    printf("%s7: %s %s %s %s\n", notes[index], notes[index], notes[middleIndexL], notes[middleIndexR], 
                                                            notes[noteAddition(middleIndexR, 3)]);

    // diminished 7th 
    middleIndexL = noteAddition(index, 3);
    middleIndexR = noteAddition(middleIndexL, 3);
    printf("%sdim7: %s %s %s %s\n\n", notes[index], notes[index], notes[middleIndexL], notes[middleIndexR], 
                                                            notes[noteAddition(middleIndexR, 3)]);
    return 0;
}