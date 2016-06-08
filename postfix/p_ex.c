#include<stdio.h>
#include"Stack.c"
#include<string.h>
#include<math.h>
int evaluate_postfix(char *str)
{
       char*p=strtok(str," ");
       Stack*st=stack_new();
       int t=0,k,final_res,n;
       int r;
       while(p!=NULL)
       {
       t=stack_size(st);
       if(t<=1 && (*p=='+' || *p=='-' || *p=='*' || *p=='/'))
       break;
       else if(t>1 && (*p=='+' || *p=='-' || *p=='*' || *p=='/')){
       if(*p=='+')
       final_res=stack_top(st)+st->link->data;
       else if(*p=='-')
       final_res=st->link->data-stack_top(st);
       else if(*p=='*')
       final_res=stack_top(st)*st->link->data;
       else if(*p=='/')
       final_res=st->link->data/stack_top(st);
       st=stack_pop(st);
       st->data=final_res;
     }else{
     n=strlen(p);
     r=0;
     while(n>0)
      {
       k=(int)(*p);
        r=r+(k-48)*pow(10,n-1);
        n--;
       p++;
      }
      st=stack_push(st,r);
      }
      p=strtok(NULL," ");
     }
     return final_res;
}
int main()
{
     char str[50];
      int result;
    if(fgets(str,50,stdin)!=NULL)
     result=evaluate_postfix(str);
    printf("Final avlue is : %d\n",result);
    return 0;
}

