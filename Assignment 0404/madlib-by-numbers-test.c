/*
 * madlib-by-numbers-test.c
 * Author: Patrick Utz
 * Date: 04.04.2019
 * 
 * A C program that tests madlib-by-numbers.c
 */

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "madlib-by-numbers.h"

int main() {
    char* words_to_use1[] = { "swim", "brilliant", "git" };
    char* template1 = "The 1 2 likes to 0 in the 1 moonlight";
    
    char* words_to_use2[] = { "pretend", "there's", "10" };
    char* template2 = "The 1 2 3 4 over the bridge";
    
    char* words_to_use3[] = { "car", "red" };
    char* template3 = "There is a 1 0 in the big 295 tunnel";
    
    char* words_to_use4[] = { };
    char* template4 = "There's no insertion";
    
    char* message1 = madlib_by_numbers(template1, 3, words_to_use1);
    assert(
           strcmp("The brilliant git likes to swim in the brilliant moonlight", message1) == 0
           );
    free(message1);

    char* message2 = madlib_by_numbers(template2, 10, words_to_use2);
    assert(
           strcmp("", message2) == 0
           );
    free(message2);

    char* message3 = madlib_by_numbers(template3, 2, words_to_use3);
    assert(
           strcmp("There is a red car in the big 295 tunnel", message3) == 0
           );
    free(message3);

    char* message4 = madlib_by_numbers(template4, 0, words_to_use4);
    assert(
           strcmp("There's no insertion", message4) == 0
           );
    free(message4);
    return 0;
}
