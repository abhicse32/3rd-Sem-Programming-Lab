typedef struct node_struct{
    int key;
    struct node_struct* left;
    struct node_struct* right;
} node;

int search(int key, int* array, int size);
node* make_bst(int* inorder_array, int* preorder_array, int size);

void print_postorder(node* root);
void print_inorder(node* root);
