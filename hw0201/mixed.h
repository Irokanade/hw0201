//
//  mixed.h
//  hw0201
//
//  Created by Michael Leong on 2021/3/20.
//

#ifndef mixed_h
#define mixed_h

#include <stdio.h>

typedef struct _sMixedNumber {
    long int integerPart;
    long int numerator;
    long int denominator;
} sMixedNumber;

long int gcd(long int num1, long int num2);
void convertToImproper(sMixedNumber *result, sMixedNumber original);
void convertToProper(sMixedNumber *result, sMixedNumber original);
int mixed_set( sMixedNumber *pNumber , int32_t a, int32_t b,
int32_t c);
// return -1 if invalid; otherwise , return 0.
int mixed_print( const sMixedNumber number);
// in the form of (a,b,c)
void rational_add( sMixedNumber *pNumber , const sMixedNumber r1
, const sMixedNumber r2);
// pNumber = r1 + r2
void rational_sub( sMixedNumber *pNumber , const sMixedNumber r1
, const sMixedNumber r2);
// pNumber = r1 - r2
void rational_mul( sMixedNumber *pNumber , const sMixedNumber r1
, const sMixedNumber r2);
// pNumber = r1 * r2
void rational_div( sMixedNumber *pNumber , const sMixedNumber r1
, const sMixedNumber r2);
// pNumber = r1 / r2

#endif /* mixed_h */
