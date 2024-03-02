#ifndef DOUBLE_ARITHMETIC_H
#define DOUBLE_ARITHMETIC_H

    #ifdef __cplusplus
    extern "C" {
    #endif /*__cplusplus*/
        #include <stdint.h>

        extern double double_add      (double num1, double num2);
        extern double double_subtract (double num1, double num2);
        extern double double_multiply (double num1, double num2);
        extern double double_division (double num1, double num2);

    #ifdef __cplusplus
    }
    #endif /*__cplusplus*/

#endif /*DOUBLE_ARITHMETIC_H*/