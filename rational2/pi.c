/*
 * Abhishek Yadav
 * Compute pi using continued fractions
 */

#include "rational.h"
#include<stdio.h>
#define PI (3.141592653589793)
int main()
{
        //array initialization
	int a[]={3,7,15,1,292,1,1,1,2,1,3,1,14,2,1,1,2,2,2,2,1,84};
	rational p,q;
	int k;
	double rel_error;      //variable to store the relative error
	scanf("%d",&k);
	p=rational_from_int(a[--k]);      //converting last integer in continued fraction to rational
	
	while(k>0)
	{
	    q=rational_reciprocate(p);    //gets reciprocal of the rational number
	    p=rational_from_int(a[--k]);
	    p=rational_add(p,q);            //adds two rational numbers by function call
	}
	double val=rational_to_double(p);    //converts the resultant rational to double 
	if(val>PI)
	    rel_error=(val-PI)/PI;           
	else 
	    rel_error=(PI-val)/PI;
	printf("value of PI is: %lf and relative error is : %e\n",val,rel_error);
	return 0;
}

