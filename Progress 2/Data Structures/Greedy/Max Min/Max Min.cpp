#include <bits/stdc++.h>

using namespace std;

/**************************EDITABLE PART******************/
int maxMin(int k, vector<int> arr) {
    sort(arr.begin(), arr.end());   // sort array in ascending order
    int len = arr.size();        
    
    int min = arr.back() - arr.front(); // insert default minimum difference value

    // do iteration until last element that can a group consist of k element
    for (int i=0; i<len-k+1; i++){
        if ((arr[i+k-1]-arr[i])<min)    // check if difference of first and last element in group is smaller than previous value
            min=arr[i+k-1]-arr[i];
    }
    return min;
}
/********************************************************/

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    int result = maxMin(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
