/*
 * madlib-test.c
 * Author: Patrick Utz
 * Date: 04.04.2019
 * 
 * A C program that tests madlib.c
 */

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "madlib.h"

int main() {
    char* template1 = "The %s %s likes to %s in the moonlight";
    char* message1 = madlib(template1, "brilliant", "git", "swim");

    char* template2 = "The %s %s will %s over the bridge";
    char* message2 = madlib(template2, "sexy", "man", "jump");

    char* template3 = "The %s %s never %s in the race";
    char* message3 = madlib(template3, "dumb", "horse", "ran");

    char* template4 = "The %s %s %s me in the face";
    char* message4 = madlib(template4, "yummy", "burger", "slapped");
    
    assert(
        strcmp("The brilliant git likes to swim in the moonlight", message1) == 0
    );
    assert(
        strcmp("The sexy man will jump over the bridge", message2) == 0
    );
    assert(
        strcmp("The dumb horse never ran in the race", message3) == 0
    );
    assert(
        strcmp("The yummy burger slapped me in the face", message4) == 0
    );
    free(message1);
    free(message2);
    free(message3);
    free(message4);
    return 0;
} 

