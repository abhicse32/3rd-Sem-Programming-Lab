#include"bst.h"
#include <stdlib.h>
#include<stdio.h>
node* create_node(int data)
{
   node*p=malloc(sizeof(node));
   p->key=data;
   p->left=NULL;
   p->right=NULL;
   return p;
}
node* bst_add_num(node* root, int num)
{
   if(root==NULL)
   return (create_node(num));
   else if(num<=root->key)
     root->left=bst_add_num(root->left,num);
    else if(num>root->key)
    root->right=bst_add_num(root->right,num);
    return root;
}
node* search_node(node* root, int num, node* flag_root,My_queue* turn_roots)
{
    if(flag_root->key==num)
    return root;
   else if(num>root->key)
    {
     if(root->right->key==num)
        { 
          if(turn_roots!=NULL)
              return create_root(root,num,flag_root,turn_roots);
           else{
           node*p=create_node(num);
           node*y=root->right;
           root->right=y->left;
             p->left=flag_root;
             p->right=y->right;
            return p;
           }
       }
     else if(root->right->key>num)
           turn_roots=add_node(turn_roots,root);
      
     root=search_node(root->right,num,flag_root,turn_roots);
      return root;
   }
   else if(num<=root->key)
   {
       if(root->left->key==num)
        {
          // printf("%d\n",my_queue_size(turn_roots));
             if(turn_roots!=NULL)
                return create_root(root,num,flag_root,turn_roots);
             else{
                node*p=create_node(num);
                node*q=root->left;
               p->right=flag_root;
               p->left=q->left;
               root->left=q->right;
            return p;
          }
         
         }
       else if(root->left->key<num)
        turn_roots=add_node(turn_roots,root);
        
       root=search_node(root->left,num,flag_root,turn_roots);
   }
   return root;
}
void print_treestyle(node* root,My_queue*t,int level)
{
    if(root==NULL || t==NULL)
    return;
    else 
    {
    
         if(level==0){
         level=my_queue_size(t);
         printf("\n");
         }
        printf("%d ",t->node1->key); 
        if(t->node1->left!=NULL)
         t=add_node(t,t->node1->left);
         if(t->node1->right!=NULL)
         t=add_node(t,t->node1->right);
         
         t=queue_pop2(t);
         if(t!=NULL)
         print_treestyle(t->node1,t,--level);
   }
   return ;
}
node*create_root(node* curr_node, int num, node* flag_root,My_queue* turn_roots)
{
        node*p=create_node(num);
        if(num<=flag_root->key){
        p->right=flag_root;
        p->left=turn_roots->node1->left;
        }
        else{
          p->left=flag_root;
          p->right=turn_roots->node1->right;
        }
        while(turn_roots->next!=NULL){
             if(turn_roots->node1->key > num)
             turn_roots->node1->left=turn_roots->next->node1->right;
             else
             turn_roots->node1->right=turn_roots->next->node1->left;
             
             turn_roots=turn_roots->next;
        }
        if(turn_roots->node1->key<num){
        node*st=curr_node->left;
        turn_roots->node1->right=st->left;
        curr_node->left=st->right;
        free(st);
        }
        else {
         node*st=curr_node->right;
        turn_roots->node1->left=st->right;
        curr_node->right=st->left;
        free(st);  
        }
        return p;
}

My_queue*add_node(My_queue*queue,node*root)
{
    My_queue*k=queue;
     My_queue*p=malloc(sizeof(My_queue));
     p->node1=root;
     p->next=NULL;
     if(queue==NULL)
      queue=p;
     else {
           while(k->next!=NULL)
           k=k->next;
            k->next=p;
         }
         return queue;  
}
My_queue* queue_new2()
{
    My_queue*q=malloc(sizeof(My_queue));
    q=NULL;
    return q;
}

My_queue* queue_pop2(My_queue*q)
{
    if(q==NULL)
    return q;
   My_queue*p=malloc(sizeof(My_queue));
   p=q;
   q=p->next;
   free(p);
   return q;
}
int my_queue_size(My_queue*q)
{
    int i=0;
    while(q!=NULL)
    {
       q=q->next;
       i++;
    }
    return i;
}

