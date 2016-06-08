#include "bst.h"
#include <malloc.h>

int search(int key, int* array, int size){
    int i;
    for(i = 0; i < size; i++){
        if (array[i] == key) {
            return i;
        }
    }

    return -1;
}

node* make_bst(int* inorder_array, int* preorder_array, int size){

    if (size == 0){
        return NULL;
    }
    // Create a new node.
    node* root_node = (node*) malloc(sizeof(node));
    
    // Set root key.
    int root_key = preorder_array[0];
    root_node->key = root_key;

    // Search for root key in inorder_array.
    int root_key_pos = search(root_key, inorder_array, size);

    // Make recursive call to get left 
    // and right subtrees from this.
    root_node->left = make_bst(inorder_array, preorder_array + 1,
                               root_key_pos);
    root_node->right = make_bst(inorder_array + root_key_pos + 1,
                                preorder_array + root_key_pos + 1,
                                size - root_key_pos - 1);

    return root_node;
}

void print_postorder(node* root){
    if (root == NULL)
        return;
    print_postorder(root->left);
    print_postorder(root->right);
    printf("%d, ", root->key);

    return;
}

void print_inorder(node* root){
    // Write your code here.
}
