#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {
    stack<string> textStack;
    int opNumber;
    int opSelect;
    string str;

    // use stack to store the previous element
    // use string as a dynamic array
    cin >> opNumber;
    for(int i=0; i<opNumber; i++){
        cin >> opSelect;

    // check the selector
        // insert character
        if (opSelect == 1){            
            string insertStr;
            cin >> insertStr;
            textStack.push(str);    // insert the previous str character to stack
            str = str + insertStr;  // insert the new entered character to string
        }
        // delete n character
        else if (opSelect == 2){
            int deleteStack;
            cin >> deleteStack;
            textStack.push(str);    // insert the previous str character to stack
            str.erase(str.size() - deleteStack);    // erase the string from n-th element to the end
        }
        // print n character
        else if (opSelect == 3){
            int printStack;
            cin >> printStack;
            cout << str[printStack - 1] << endl;    // print last n-th element from string
        }
        // reset to previous element
        else{
            str = textStack.top();  // get the previous character from the stack
            textStack.pop();        // erase the last previous character
        }       
    }
    return 0;
}
