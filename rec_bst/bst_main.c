#include <stdio.h>
#include"bst.h"
#include<stdlib.h>
int main(){
    node* root_ptr;

    int N,N_S;
    scanf("%d%d",&N,&N_S);
    int*ar=malloc(N*sizeof(int));
    int i;
    for(i=0;i<N;i++)
    scanf("%d",&ar[i]);
    root_ptr = NULL;
    My_queue*turn_root;
    for(i=0;i<N;i++){
    
          root_ptr=bst_add_num(root_ptr,ar[i]);
          turn_root=queue_new2();
          root_ptr=search_node(root_ptr,ar[i],root_ptr,turn_root); 
          free(turn_root);
   }
    int*arr1=(int*)malloc(N_S*sizeof(int));
    for(i=0;i<N_S;i++)
    {
        scanf("%d",&arr1[i]);
       turn_root=queue_new2();
       root_ptr=search_node(root_ptr,arr1[i],root_ptr,turn_root); 
         free(turn_root);
    }
    int level=0;
    My_queue*t=queue_new2();
     t=add_node(t,root_ptr);
    print_treestyle(root_ptr,t,level);
    printf("\n");
    return 0;
}

