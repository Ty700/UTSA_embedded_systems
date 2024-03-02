#include <stdio.h>

#include "int_arithmetic.h"

#include "double_arithmetic.hpp"

int main(int argc, char *argv[]){

    printf("Add: %d\n", int_add(3,2));
    printf("Subtract: %d\n", (int_add(3,2) - 2));
    
    printf("Division: %0.2f\n", double_division(3,2));
    printf("Multiply: %0.2f\n", double_multiply(2,2));
} 