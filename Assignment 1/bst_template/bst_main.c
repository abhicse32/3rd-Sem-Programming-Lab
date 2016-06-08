/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

* File Name : bst.c

* Purpose : Practice code for inorder and preorder traversal string
*           to bst conversion.

* Creation Date : 12-07-2013

* Last Modified : Saturday 03 August 2013 01:32:57 PM IST

* Created By : Y Devesh

_._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
#include "bst.h"

int main(){
    int size = 7;
    int inorder_array[] = {5, 15, 18, 20, 22, 25, 30};
    int preorder_array[] = {20, 15, 5, 18, 25, 22, 30};

    node* root_ptr;

    root_ptr = make_bst(inorder_array, preorder_array, size);

    // Print postorder
    printf("Printing Post Order\n");

    print_postorder(root_ptr->left);
    print_postorder(root_ptr->right);
    printf("%d\n", root_ptr->key);
    return 0;
}
// That's all folks!
