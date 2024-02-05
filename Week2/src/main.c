#include <stdio.h>

#include "int_arithmetic/libarithmetic.a"

int main(int argc, char *argv[]){

    printf("Add: %d\n", int_add(3,2));
    printf("Subtract: %d\n", (int_add(3,2) - 2));

} 