//
//  mixed.c
//  hw0201
//
//  Created by Michael Leong on 2021/3/20.
//

#include "mixed.h"

long int gcd(long int num1, long int num2) {
    long int i = 0;
    
    if(num1 < 0) {
        num1 *= -1;
    }
    
    if(num2 < 0) {
        num2 *= -1;
    }
    
    while(num2 != 0) {
        i = num1 % num2;
        num1 = num2;
        num2 = i;
    }
    
    return num1;
}

//convert to improper fraction
void convertToImproper(sMixedNumber *result, sMixedNumber original) {
    int sign = 1;
    *result = original;
    
    if(result->numerator <= 0) {
        //nothing to convert
        return;
    } else if(result->integerPart < 0) {
        sign = -1;
        result->integerPart *= -1;
    }
    
    while(result->integerPart > 0) {
        result->numerator += result->denominator;
        result->integerPart--;
    }
    
    result->numerator *= sign;
    
    printf("result: ");
    mixed_print(*result);
    printf("\n");
    return;
}

void convertToProper(sMixedNumber *result, sMixedNumber original) {
    *result = original;
    int sign = 1;
    
    if(result->integerPart != 0) {
        //invalid improper fraction
        return;
    }
    
    if(result->numerator < 0) {
        sign = -1;
        result->numerator *= -1;
    }
    
    while(result->numerator >= result->denominator) {
        result->numerator -= result->denominator;
        result->integerPart++;
    }
    
    result->integerPart *= sign;
    printf("result: ");
    mixed_print(*result);
    printf("\n");
    return;
}

int mixed_print( const sMixedNumber number) {
    printf("(%ld,%ld,%ld)", number.integerPart, number.numerator, number.denominator);
    
    return 0;
}

void rational_add( sMixedNumber *pNumber , const sMixedNumber r1
                  , const sMixedNumber r2) {
    pNumber->integerPart = 0;
    pNumber->numerator = 0;
    pNumber->denominator = 0;
    sMixedNumber improperR1 = r1;
    sMixedNumber improperR2 = r2;
    long int commonDenom = r1.denominator*r2.denominator;
    
    convertToImproper(&improperR1, r1);
    convertToImproper(&improperR2, r2);
    pNumber->numerator = improperR1.numerator*improperR2.denominator + improperR2.numerator*improperR1.denominator;
    pNumber->denominator = commonDenom;
    
    convertToProper(pNumber, *pNumber);
    
    /*pNumber->integerPart = r1.integerPart + r2.integerPart;
    pNumber->denominator = commonDenom;
    pNumber->numerator = r1.numerator*r2.denominator + r2.numerator*r1.denominator;
    while(pNumber->numerator >= commonDenom) {
        pNumber->numerator -= commonDenom;
        pNumber->integerPart++;
    }*/
    
    long int gcdNum = gcd(pNumber->denominator, pNumber->numerator);
    pNumber->numerator /= gcdNum;
    pNumber->denominator /= gcdNum;
}

void rational_sub( sMixedNumber *pNumber , const sMixedNumber r1
                  , const sMixedNumber r2) {
    pNumber->integerPart = 0;
    pNumber->numerator = 0;
    pNumber->denominator = 0;
    sMixedNumber improperR1 = r1;
    sMixedNumber improperR2 = r2;
    long int commonDenom = r1.denominator*r2.denominator;
    
    convertToImproper(&improperR1, r1);
    convertToImproper(&improperR2, r2);
    pNumber->numerator = improperR1.numerator*improperR2.denominator - improperR2.numerator*improperR1.denominator;
    pNumber->denominator = commonDenom;
    
    convertToProper(pNumber, *pNumber);
    /*pNumber->integerPart = r1.integerPart - r2.integerPart;
    pNumber->denominator = commonDenom;
    if((r1.numerator*r2.denominator < r2.numerator*r1.denominator) && pNumber->integerPart > 0) {
        pNumber->numerator = (r1.numerator*r2.denominator+commonDenom) - r2.numerator*r1.denominator;
        pNumber->integerPart--;
    } else {
        pNumber->numerator = r1.numerator*r2.denominator - r2.numerator*r1.denominator;
    }
    
    if(pNumber->integerPart < 0 && pNumber->numerator < 0) {
        pNumber->numerator *= -1;
    }*/
    
    long int gcdNum = gcd(pNumber->denominator, pNumber->numerator);
    pNumber->numerator /= gcdNum;
    pNumber->denominator /= gcdNum;
}

void rational_mul( sMixedNumber *pNumber , const sMixedNumber r1
                  , const sMixedNumber r2) {
    sMixedNumber improperR1 = r1;
    sMixedNumber improperR2 = r2;
    pNumber->integerPart = 0;
    pNumber->numerator = 0;
    pNumber->denominator = 0;
    
    convertToImproper(&improperR1, r1);
    convertToImproper(&improperR2, r2);
    
    pNumber->numerator = improperR1.numerator*improperR2.numerator;
    pNumber->denominator = improperR1.denominator*improperR2.denominator;
    
    convertToProper(pNumber, *pNumber);
    
    long int gcdNum = gcd(pNumber->denominator, pNumber->numerator);
    pNumber->numerator /= gcdNum;
    pNumber->denominator /= gcdNum;
}

void rational_div( sMixedNumber *pNumber , const sMixedNumber r1
                  , const sMixedNumber r2) {
    sMixedNumber improperR1 = r1;
    sMixedNumber improperR2 = r2;
    pNumber->integerPart = 0;
    pNumber->numerator = 0;
    pNumber->denominator = 0;
    
    convertToImproper(&improperR1, r1);
    convertToImproper(&improperR2, r2);
    
    pNumber->numerator = improperR1.numerator*improperR2.denominator;
    pNumber->denominator = improperR1.denominator*improperR2.numerator;
    
    convertToProper(pNumber, *pNumber);
    
    long int gcdNum = gcd(pNumber->denominator, pNumber->numerator);
    pNumber->numerator /= gcdNum;
    pNumber->denominator /= gcdNum;
}
