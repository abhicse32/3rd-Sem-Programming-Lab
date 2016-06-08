typedef struct node_struct{
    int key;
    struct node_struct* left;
    struct node_struct* right;
} node;

typedef struct new_Queue{
       struct new_Queue*next;
       struct node_struct *node1;
}My_queue;
   
node* search_node(node* root, int,node*flag,My_queue*);
My_queue*add_node(My_queue*,node*);

My_queue* queue_new2();

My_queue* queue_push2(My_queue*,node*);
int my_queue_size(My_queue*);

My_queue* queue_pop2(My_queue*);
node* bst_add_num(node* root, int);

void print_treestyle(node*,My_queue*,int);

node*create_root(node* curr_node, int num, node* flag_root,My_queue* turn_roots);
