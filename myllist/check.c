#include<stdio.h>
#include"LList.c"
int main()
{
    LList *p=llist_new();
    int k=llist_size(p);
    printf("%d\n",k);
    llist_print(p);
    k=llist_get(p,4);
    printf("%d\n",k);
    
        p=llist_append(p,7);
      
     llist_print(p);
     p=llist_remove_first(p);
     k=llist_size(p);
     printf("%d\n",k);
    return 0;
}
