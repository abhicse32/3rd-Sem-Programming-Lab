/*
 * Author: Abhishek Yadav
 * Rational data structure (Implementation)
 */

#include "rational.h"
#include<math.h>
#include<malloc.h>
#include<stdio.h>

//definition of the function
rational make_rational(int p, int q){
    //calling function gcd
    int k=gcd(p,q);
     //memory allocation to rational
    rational* var1=malloc(sizeof(rational)); 
    
    //numerator and denominator are stored through pointer 
    var1->numerator=p/k;
    var1->denominator=q/k;
    rational b;
    b=*var1;       //assigning the values stored in rational pointer to rational variable
    return b;
}

// function definition
rational rational_parse ( char* str ){
   //initialize two character pointers
    char *str1;
     char *str2;
     while(*str!='/'){
     str1=str;           //assigns all the characters left to '/' to character pointer
     str++;
     str1++;
}
*str1='\0';
 while(*++str!='\0'){
    str2=str;            //assigns all the characters right to '/' to character pointer
    str2++;    
}  
   *++str2='\0'; 
 unsigned long len1=sizeof(str1);
 unsigned long len2=sizeof(str2);
 int p=1,i=1;
 while(i<=len1-1)
 {
         p*=10;    //gets powers of 10 to multiply with appropriate digit
         i++;
         }
 // declaring two integer variables to store numerator and denominator     
 int num_1=0;
 int num_2=0;
 
 //conversion of string1 to integer
 while(len1-1!=0){
   num_1=num_1+((int)(*str1)-48)*p;   
   p/=10;
   len1--;             
   str1++;
}
 p=1,i=1;
 while(i<=len2-1)
 {
         p*=10;
         i++;
         }
 //conversion of  string2 to integer     
while(len2-1!=0){
    num_2=num_2+((int)(*str2)-48)*p;
    len2--;
    str2++;
    p/=10;
  }                               //calculation of denominator
  rational var2;
  //function call to get a rational number
  var2=make_rational(num_1,num_2);
  return var2;
 } 
 
//function definition
void rational_print(rational q){
   if(q.denominator==0)
    printf("indefinite number\n");
    else
   printf("rational number is %d/%d\n",q.numerator,q.denominator);
}

//function definition
rational rational_from_int ( int p ) {
       rational var3;
       var3.numerator=p;
       var3.denominator=1;
       return var3;             //returns rational value of an integer
}

//function definition to convert a rational number to double
double rational_to_double ( rational p )
{
  return (double)(p.numerator)/(double)(p.denominator);
}

//function definition to add two rational numbers
rational rational_add ( rational p, rational q )
{
      int a,b;
      a=p.numerator*q.denominator+p.denominator*q.numerator;     //calculation of numerator of resulting rational number
      b=p.denominator*q.denominator;                             //getting denominator 
      rational output1;
      int t=gcd(a,b);                    //call function gcd() to get the gcd of numerator and denominator 
      output1.numerator=a/t;           //divides  numerator and denominator by their gcd
      output1.denominator=b/t;
      return output1;                      
}

//function definition to subtract two rational numbers
rational rational_sub ( rational p, rational q )
{
      rational output2;
      
       //calculation of numerator and denominator of resulting rational number
      output2.numerator=p.numerator*q.denominator-p.denominator*q.numerator;
      output2.denominator=p.denominator*q.denominator;
      if (output2.numerator<0)
              output2.numerator*=-1;
       int t;
       t=gcd(output2.numerator,output2.denominator);          //call and calculate gcd of numerator and denominator
       output2.numerator=output2.numerator/t;
       output2.denominator=output2.denominator/t;
        return output2;
}

//function definition to multiply to rational numbers
rational rational_mul ( rational p, rational q )
{
    rational output3;
    output3.numerator=p.numerator*q.numerator;
    output3.denominator=p.denominator*q.denominator;
    int m;
       m=gcd(output3.numerator,output3.denominator);
       output3.numerator=output3.numerator/m;
       output3.denominator=output3.denominator/m;
        return output3;
}

//function definition to divide rational numbers 
rational rational_div ( rational p, rational q )
{
    rational output4;
    output4.numerator=p.numerator*q.denominator;
    output4.denominator=p.denominator*q.numerator;
    int n;
       n=gcd(output4.numerator,output4.denominator);
       output4.numerator=output4.numerator/n;
       output4.denominator=output4.denominator/n;
        return output4;
}

//function definition to get the reciprocal of a rational number
rational rational_reciprocate( rational p ) 
{
    rational output5;
     output5.numerator=p.denominator;
     output5.denominator=p.numerator;
      int k;
       k=gcd(output5.numerator,output5.denominator);
       output5.numerator=output5.numerator/k;
       output5.denominator=output5.denominator/k;
        return output5;
}

//function definition to get the gcd of two numbers
int gcd ( int a, int b )
{

// check for negative values
        if(a<0 && b<0)
     {
        a*=-1;
        b*=-1;
     }
     else if(a<0 && b>0)
         a*=-1;
     else if(a>0 && b<0)
         b*=-1;
       
      if (a%b==0)
         return b;
     else{
        if(a>b)
           gcd(b,a%b);    //recursively calculates the gcd
        else 
           gcd(b,a);
     }
}




