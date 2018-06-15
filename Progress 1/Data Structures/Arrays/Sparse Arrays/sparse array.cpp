#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

// make function to compare array and count the matches component using unordered mapping
int compareArray (unordered_multimap<string, int> strComponent, string query){
    return (int)(strComponent.count(query));    // using count function in unordered multimap to lookup element with specific key
}

int main(){
    int strSize, querySize;
    unordered_multimap<string, int> strComponent;
    vector<int> result;     // make a dynamic array to save result
    
    cin >> strSize;
    
    // collecting string value
    for (int i=0; i<strSize; i++){
        string tempString;
        cin >> tempString;  // read the string value
        strComponent.insert(make_pair(tempString, 0));  // inserting the value to array with the key value
    }
    
    cin >> querySize;
    
    // collecting queries value
    for(int i=0; i<querySize; i++){
        string tempQuery;
        cin >> tempQuery;   // read the query component
        result.push_back(compareArray(strComponent, tempQuery));    // add new compared value to the tail of dynamic array
    }
    
    // print the result
    for (int i=0; i<result.size(); i++){
        cout << result[i] << "\n";
    }
    
    return 0;
}