/* ----------------------------------------------------------------------------------------
  Euclid’s algorithm for calculating the greatest common divisor (GCD) of two numbers. This is the 
  C program that handles arguments from the command line and passes them to the respective gcd.asm
  that then returns the proper gcd of values x and y.
  
  To assemble and run:

     nasm -felf64 gcd.asm && gcc -no-pie callgcd.c gcd.o && ./a.out x y
 ---------------------------------------------------------------------------------------- */

#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

uint64_t gcd(uint64_t x, uint64_t y);

int checkArgs(int argc, char *argv[]) {
  // check if there are only two numbers being passed in
  if (argc != 3) {
    return 1;
  }
  
  // check if only positive numbers are passed in
  int firstNum = atoi(argv[1]);
  int secondNum = atoi(argv[2]);
  if (firstNum < 0 || secondNum < 0) {
    return 1;
  }

  return 0;
}

int main(int argc, char *argv[]) {
  // pass is 0 if the arguments are valid and 1 if not valid
  int pass = checkArgs(argc, argv);
  
  if (pass == 0) {
    uint64_t x = atoi(argv[1]);
    uint64_t y = atoi(argv[2]);
    printf("The GCD of %lu and %lu is %lu.\n", x, y, gcd(x, y));
  } else {
    printf("This program requires exactly two non-negative integer command line arguments.\n");
  }

  return 0;
}
