//
//  hw0201.c
//  hw0201
//
//  Created by Michael Leong on 2021/3/20.
//

#include <stdio.h>
#include "mixed.h"

int main() {
    //printf("gcd %ld\n", gcd(45,21));
    
    sMixedNumber num1 = {-5,4,5};
    sMixedNumber num2 = {2,9,10};
    sMixedNumber result;
    
    printf("num1:\n");
    mixed_print(num1);
    printf("\nnum2\n");
    mixed_print(num2);
    printf("\nadd:\n");
    rational_add(&result, num1, num2);
    mixed_print(result);
    printf("\nsub:\n");
    rational_sub(&result, num1, num2);
    mixed_print(result);
    printf("\nmultiply\n");
    rational_mul(&result, num1, num2);
    mixed_print(result);
    printf("\ndivide\n");
    rational_div(&result, num1, num2);
    mixed_print(result);
    
    return 0;
}
