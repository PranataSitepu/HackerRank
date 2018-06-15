/*
struct node
{
    int data;
    node* left;
    node* right;
};
*/

// preOrder traversal is Depth First Search (DFS) and read in root-left-right order
void preOrder(node *root) {
    // check if tree is empty
    if (root == NULL)
        return;
    
    printf("%d ", root->data); 	// print the root value
    preOrder(root->left);		// take the left branch and assign the leaf as the new root
    preOrder(root->right);		// take the right branch and assign the leaf as the new root
}