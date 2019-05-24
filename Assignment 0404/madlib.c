/*
 * madlib.c
 * Author: Patrick Utz
 * Date: 04.04.2019
 * 
 * A C program that takes in a template and can format a C string where each %s placeholder 
 * is replaced by the given adjective, noun, and verb strings
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "madlib.h"

char* madlib(char* template, char* adjective, char* noun, char* verb) {
    char* output = malloc(strlen(template) + strlen(adjective) + strlen(verb));
    strcpy(output, "");
    sprintf(output, template, adjective, noun, verb);
    return output;
}

