#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// make a new data type
struct CustomerType{
    int arrival, duration;
};

// make a new type for sorting
struct compare{
    bool operator() (CustomerType &a, CustomerType &b){
        return a.duration > b.duration;
    }
};

// comparator a<b
bool operator < (CustomerType a, CustomerType b){
    return a.arrival < b.arrival;
}

int main()
{
    int n;
    cin >> n;
    
    //make dynamic array to store customer arrival time and cook duration
    vector<CustomerType> customers;

    // make a sorted heap
    priority_queue<CustomerType, vector<CustomerType>, compare> minHeap;
    
    for (int i=0; i<n ;i++){
        int a, d;
        cin >> a >> d;
        CustomerType listCustomer;
        listCustomer.arrival = a;
        listCustomer.duration = d;
        customers.push_back(listCustomer);
    }
    
    // sort the input customer data in ascending order
    sort(customers.begin(), customers.end());
    long arrivalTime = 0;
    long waitingTime = 0;
    int i;
    int idx=0;
    
    while (true){
        for (i=idx; i<n; i++){

            // check if there is customer that arrive faster than previous arrival time
            if (customers[i].arrival <= arrivalTime){
                minHeap.push(customers[i]); // insert faster customer to heap
            }
            else{
                idx = i;    // make the next cycle start from the last element checked
                break;
            }
        }
        
        if (i == n)
            idx = n;
        
        if(!minHeap.empty()){
            CustomerType tmp = minHeap.top();
            waitingTime += arrivalTime + tmp.duration - tmp.arrival;
            arrivalTime += tmp.duration;
            minHeap.pop();
        } 
        else{
        // minHeap is empty
        // assign the customer arrival as the slowest arrival time
            if (idx != n)
                arrivalTime = customers[idx].arrival;
        }
        
        if  (idx == n && minHeap.empty())
            break;
    }
    cout << waitingTime/n << "\n";
    return 0;
}