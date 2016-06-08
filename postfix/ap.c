#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char str[]="43592";
    int n=strlen(str);
    int r=0,i=0,k;
    while(str[i]!='\0')
    {
       k=(int)str[i];
        r=r+(k-48)*pow(10,n-1);
        n--;i++;
    }
    printf("%d  \n",r);
    return 0;
}
