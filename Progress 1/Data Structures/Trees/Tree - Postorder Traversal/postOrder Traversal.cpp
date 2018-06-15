/*
struct node
{
    int data;
    node* left;
    node* right;
};
*/

// postOrder traversal is Depth First Search (DFS) and read in left-right-root order
void postOrder(node *root) {
    // check if tree is empty
    if (root == NULL)
        return;
 
     postOrder(root->left);     // take the left branch and assign the leaf as the new root
     postOrder(root->right);    // take the right branch and assign the leaf as the new root
     printf("%d ", root->data); // print the root value
}