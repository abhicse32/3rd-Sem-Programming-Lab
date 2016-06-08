/*
 * Author: Abhishek Yadav
 * Polynomial data structure
 */

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

  
typedef struct polynomial_2
{
   int deg_poly;               //variable to store the degree of the polynomial
   double coeffs_poly[20];      //array stores the plynomial coefficients
   double poly;                 // stores double value of polynomial
   } polynomial;

// Construct a polynomial from a list of 'n' coefficients stored in 'coeffs'.
polynomial polynomial_construct ( int n, double coeffs[] );

// Print the polynomial q in the format a0 x^0 + a1 x^1 ...
void polynomial_print ( polynomial p );

// Evaluate the polynomial p at the value x
double polynomial_evaluate ( polynomial p, double x );

// Operations on polynomials
polynomial polynomial_add ( polynomial p, polynomial q );
polynomial polynomial_sub ( polynomial p, polynomial q );     // subtracts q from p
polynomial polynomial_mul ( polynomial p, polynomial q );
polynomial polynomial_diff ( polynomial p );
polynomial polynomial_integrate ( polynomial p );

#endif // POLYNOMIAL_H

