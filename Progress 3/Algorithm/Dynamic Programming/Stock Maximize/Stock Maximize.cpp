#include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;

    while (t--){
        int n;
        cin >> n;
        
        int prices[n];
        long profit = 0, maxPrice = 0;
        
        for (int i = 0; i < n; i++)
            cin >> prices[i];

        for (int i=n-1; i>=0; i--){
            if(prices[i] >= maxPrice){
                maxPrice = prices[i];
            }
            profit += maxPrice - prices[i];
        }
        fout << profit << "\n";
    }

    fout.close();

    return 0;
}
