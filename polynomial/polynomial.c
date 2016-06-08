/*
 * Author: <Your Name>
 * Polynomial data structure (Implementation)
 */

#include "polynomial.h"
#include<stdio.h>
#include<math.h>
#include<malloc.h>

//function definition to construct a polynomial
polynomial polinomial_construct(int n,double coeffs[])
{
    polynomial* t=(polynomial*)malloc(sizeof(polynomial));    //assigns chunk of memory to polynomial pointer
    int i;
    double x;
    double poly;
    t->poly=0;
    for(i=0;i<n;i++){
       t->coeffs_poly[i]=coeffs[i];           //stores all the coefficients into array
       }

       t->deg_poly=n-1;
    return *t;               //returns the value at the address t
}

//functions definition to print a polynomial
void polynomial_print ( polynomial p )
{
     int counter=0;
     while(counter<=p.deg_poly)
         printf("%lf x^%d+",p.coeffs_poly[counter],counter);
         
}

//function definition to evaluate polynomial at a particular value
double polynomial_evaluate ( polynomial p, double x )
{
    int counter2=0;
    double value_x=0;
    double flag=1;
    while(counter2<=p.deg_poly)
    {
         value_x=value_x+p.coeffs_poly[counter2]*flag;     //evaluation of the polynomial
         flag*=x;
         counter2++;
    }
    return value_x;
}
//defining function to add two polynomials
polynomial polynomial_add ( polynomial p, polynomial q )
{
   int counter=0;
   
   // degree of the two plynomials is compared and all the coefficients 
   // of the resulting polynomial is assigned to the respective coefficients 
   // of the the polynomial with the higher degree
   if(p.deg_poly>q.deg_poly){
        while(counter<=q.deg_poly){ 
        
         p.coeffs_poly[counter]+=q.coeffs_poly[counter];
         counter++;
         }
         return p;
}
   else 
   {
   counter=0;
       while(counter<=p.deg_poly){
        q.coeffs_poly[counter]+=p.coeffs_poly[counter];
         counter++;  
   }
   return q;
}
}

//function definition to subtract one polynomial from another
polynomial polynomial_sub ( polynomial p, polynomial q )
{
   int counter=0;
   if(p.deg_poly>q.deg_poly){
        while(counter<=q.deg_poly){
        
         p.coeffs_poly[counter]-=q.coeffs_poly[counter];
         counter++;
         }
         return p;
}
   else 
   {
   counter=0;
       while(counter<=p.deg_poly){
        q.coeffs_poly[counter]-=p.coeffs_poly[counter];
         counter++;  
   }
   return q;
}

//function definition to multiply two polynomials
}
polynomial polynomial_mul ( polynomial p, polynomial q )
{
   double flag=0;
   int i,j,k;
     for(i=0;i<=p.deg_poly;i++)
     {
            for(j=i,k=0;j>=0;j--,k++)
            {
                    flag=flag+p.coeffs_poly[j]*q.coeffs_poly[k];       //coefficient of x^i is assigned to flag 
              }                                                        // and then it is assigned back to the first 
              p.coeffs_poly[i]=flag;                                   // coefficient of p
     }
     return p;
}

//function definition to differentiate a polynomial
polynomial polynomial_diff ( polynomial p )
{
      int  k=0;
      while(k<=p.deg_poly)
      {
          p.coeffs_poly[k]*=k;         //each coefficient is multiplied by the index 
          k++;                         //of x associated with that term
      }
      return p; 
}

//function definition to integrate a polynomial
polynomial polynomial_integrate ( polynomial p )
{
       int  k=0;
       polynomial r;
       
      while(k<=p.deg_poly)
      {
          r.coeffs_poly[k+1]=p.coeffs_poly[k]/(k+1);         //each coefficient is divided by the index 
          k++;                                              //of x associated with that term+1
      }
      return r;   
}



