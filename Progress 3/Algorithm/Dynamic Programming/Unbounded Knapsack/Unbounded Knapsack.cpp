#include <bits/stdc++.h>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while (t--){
        int n,k;
        cin >> n >> k;
        
        vector<int> arr(n);
        
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        
        vector<int> dynamicP(k+1);
        dynamicP[0] = 1;

        for(int i=0; i < n; i++){
            for (int j=arr[i]; j<=k; j++){
                dynamicP[j]+=dynamicP[j-arr[i]];
            }
        }
        
        int z = k;
        for(; (z>0)&&(!dynamicP[z]); z--);
        cout << z << endl;
    }

    return 0;
}
