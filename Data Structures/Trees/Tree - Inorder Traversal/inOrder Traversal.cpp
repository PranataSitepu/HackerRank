/*
struct node
{
    int data;
    node* left;
    node* right;
};
*/

// inOrder traversal is Depth First Search (DFS) and read in left-root-right order
void inOrder(node *root) {
    // check if tree is empty
    if (root == NULL)
        return;
    
    inOrder(root->left);		// take the left branch and assign the leaf as the new root
    printf("%d ", root->data);	// print the root value
    inOrder(root->right);		// take the right branch and assign the leaf as the new root
}