/*
 * madlib-by-numbers.c
 * Author: Patrick Utz
 * Date: 04.04.2019
 * 
 * A C program that takes in a template and can format a C string where single digits 0 to 9 
 * may be substituted by the corresponding word in the given words array.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "madlib-by-numbers.h"

char* madlib_by_numbers(char* template, int word_count, char* words[]) {
    char* output = malloc(strlen(template) + word_count*45);
    strcpy(output, "");
    if (word_count == 0) {
        strcpy(output, template);
    } else if (word_count >= 10) {
        return output;
    } else {
        int place = 0;
        for (int i = 0; i < strlen(template); i++) {
            if ((template[i] >= '0' && template[i] <= '9') && (template[i]-'0' < word_count)) {
                char* wordToInsert = words[template[i] - '0'];
                for (int j = 0; j < strlen(wordToInsert); j++) {
                    output[place] = wordToInsert[j];
                    place++;
                }
            } else {
                output[place] = template[i];
                place++;
            }
        }
    }
    return output;
}
