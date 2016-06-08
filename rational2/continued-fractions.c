/*
 * Name: Abhishek Yadav
 * Compute continued fractions
 */

#include "rational.h"
#include<stdio.h>
int main()
{ 
	int ar[4];        //array declaration
	int count=3;
	rational a,b;
	scanf("%d %d %d %d",&ar[0],&ar[1],&ar[2],&ar[3]);
	//last integer in the continued fraction is being converted to rational
	b=rational_from_int(ar[count]);
	for(count=3;count>0;count--)
	{
	    a=rational_reciprocate( b);                 //gets raciprocal of the passed rational number
	    b=rational_from_int( ar[count-1]);
	    b=rational_add(a,b);
	}
	printf("%lf",rational_to_double(b));   
	return 0;
}

