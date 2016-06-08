/*
 * Author: Abhishek Yadav
 * Finding the distance travelled by a car
 * Whose engine fails after some variable acceleration
 */

#include "polynomial.h"
#include<stdio.h>
int main()
{
	double b, T, f;              //variable declaration
	double value1,value2;
	double total_tr_dis;
	scanf("%lf %lf %lf" ,&b ,&T ,&f);
        polynomial p1,p2;                   //declaration of two polynomial variables
        
        //assigning the respective coefficients and degree to get the 
        // expression for acceleration
        p1.coeffs_poly[1]=b*T;                  
        p1.coeffs_poly[2]=-b;
        p1.deg_poly=2;
        //integrates acceleration to get the velocoty
        p1=polynomial_integrate(p1);
        p1.deg_poly=3;
        
        //calculates velocity when engine stops working
        value1=polynomial_evaluate(p1,T);
        
        //integrate velocity expression to get expression for 
        //distance travelled by the car before engine stops working
	p1=polynomial_integrate ( p1);
	p1.deg_poly=4;
	value2=polynomial_evaluate(p1,T);        //calculates the distance travelled between time interval (0,T); 
	
	double new_T=value1/f;          //initialize a variable to hold the time when car finally stops
	                                //considering initial time t=T 
	p2.deg_poly=2;                  
	p2.coeffs_poly[1]=value1;
	p2.coeffs_poly[2]=-f/2;
	
	//calculates total distance travelled by the car before it stops
	total_tr_dis=value2+polynomial_evaluate(p2,new_T);
	printf("%lf",total_tr_dis);
    return 0;
}

