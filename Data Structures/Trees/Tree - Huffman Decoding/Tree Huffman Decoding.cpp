/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;
*/

void decode_huff(node * root,string s)
{
    // make temporary tree to reset the root from the top
    node* tempRoot = root;
    
    // save each value in string s to char c and iterate until the end of s
    for(char c:s){
        
        // check the value of c
        // if True then pick the left branch, else right branch
        // save the return value in tempRoot
        tempRoot= (c == '0') ? tempRoot->left : tempRoot->right;         
        
        // check if the tree has data value in the leaf
        if (tempRoot->data){
            cout << tempRoot->data;   // print the data
            tempRoot = root;          // reset the root to the top again
        }
    }
}