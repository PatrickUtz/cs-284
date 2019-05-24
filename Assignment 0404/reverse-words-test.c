/*
 * reverse-words-test.c
 * Author: Patrick Utz
 * Date: 04.04.2019
 * 
 * A C program that tests reverse-words.c
 */

#include <assert.h>
#include <string.h>
#include <stdio.h>

#include "reverse-words.h"

int main() {

    char message1[] = "Hello, my friends!";
    reverse_words(message1);
    assert(
           strcmp("friends! my Hello,", message1) == 0
           );

    char message2[] = "  wow  ";
    reverse_words(message2);
    assert(
           strcmp("  wow  ", message2) == 0
           );

    char message3[] = "  wow";
    reverse_words(message3);
    assert(
           strcmp("wow  ", message3) == 0
           );

    char message4[] = "wow  ";
    reverse_words(message4);
    assert(
           strcmp("  wow", message4) == 0
           );

    char message5[] = "  Hello, my  friends!   ";
    reverse_words(message5);
    assert(
           strcmp("   friends!  my Hello,  ", message5) == 0
           );
    return 0;
}