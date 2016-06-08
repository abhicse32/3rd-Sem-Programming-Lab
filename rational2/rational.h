/*
 * Author: Abhishek Yadav
 * Roll No: CS12B032
 * Date:19/08/2013 
 * Rational data structure
 */

#ifndef RATIONAL_H
#define RATIONAL_H
#include<stdio.h>
typedef struct rational_2 {
      int numerator;          /*two integer data types to store numerator and denominator*/
      int denominator; 
}rational;

// Make a rational value
rational make_rational ( int p, int q );
// Parse a rational value from a string
rational rational_parse ( char* str ) ;
// Print a rational value
void rational_print ( rational q ) ;

// Convert p to a rational p/1
rational rational_from_int ( int p ) ;

// Convert rational to double
double rational_to_double ( rational p ) ;

// Operations on rational numbers
rational rational_add ( rational p, rational q ) ;
rational rational_sub ( rational p, rational q ) ;
rational rational_mul ( rational p, rational q ) ;
rational rational_div ( rational p, rational q ) ;
rational rational_reciprocate( rational p ) ;
int gcd(int a,int b);
#endif // RATIONAL_H

