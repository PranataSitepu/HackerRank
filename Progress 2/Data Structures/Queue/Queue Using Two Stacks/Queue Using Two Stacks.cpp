#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;


int main() {
    stack<int> stack1;  // rear element stack
    stack<int> stack2;  // front element stack
    int opNumber;
    int opSelect;
     
    cin >> opNumber;
    for(int i=0; i<opNumber; i++){
        cin >> opSelect;
        // insert number to the back of queue
        if (opSelect == 1){            
            int enqueue;
            cin >> enqueue;
            stack1.push(enqueue);
        }
        else{
            //move all element from the rear stack to front stack to flip the sequence
            if(stack2.empty()){
                while(!stack1.empty()){
                    stack2.push(stack1.top());
                    stack1.pop();
                }
            }
            if(!stack2.empty()){
                // dequeue the first element from queue
                if(opSelect == 2)
                    stack2.pop();
                else
                // print the first element in the queue
                    cout << stack2.top() << endl;
            }
        }   
    }
    return 0;
}
