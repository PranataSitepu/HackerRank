#include <iostream>
#include <cstddef>

using namespace std;    

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
        Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            }
            else {
                Node* cur;
                if(data <= root->data){
                    cur = insert(root->left, data);
                    root->left = cur;
                }
                else{
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }


/*********************EDITABLE FUNCTION****************************/
    int height(Node* root) {
        // Write your code here.
        if (root != NULL)
            return 1+max(height(root->left), height(root->right));  // compare the height of left branch and right branch 
                                                                    // to get the maximum depth(height)
        else
            return -1;  // if the root reach NULL, subtract the previous value with 1 because we have add 1 at the beginning
    }
}; //End of Solution
/*****************************************************************/

int main() {
    Solution myTree;
    Node* root = NULL;
    int t;
    int data;

    cin >> t;

    while(t-- > 0){
        cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.height(root);
    cout << height;

    return 0;
}