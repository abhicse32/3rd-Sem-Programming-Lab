/*
 * Author:abhishek Yadav
 * Calculating the distance travelled by the car given
 * V-velocity , A-acceleration , T-time
 */

#include "polynomial.h"
#include<stdio.h>
int main( )
{
	double v, a, t;           //variable declaration for time, acceleration and velocity
	polynomial p;
	scanf("%lf %lf %lf" ,&v,&a,&t);
	p.deg_poly=2;
	p.coeffs_poly[1] = v;                  //in formula s=vt+1/2(a*t^2) 
	p.coeffs_poly[2] = a/2;                //assign coefficient of t as v and of t^2 as a/2
	
	
	printf("%lf\n" ,polynomial_evaluate(p,t) );	
    return 0;
}

