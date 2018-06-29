#include <bits/stdc++.h>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int knightlOnAChessboard(int n, int a, int b) {
    vector<vector<int>> cache(n, vector<int>(n, INT_MAX));
    queue<pair<int,int>> que;
    que.push(make_pair(0,0));
    cache[0][0] = 0;
    
    while(!que.empty()){
        pair<int,int> currentPosition = que.front();
        que.pop();
        
        int counter = cache[currentPosition.first][currentPosition.second] + 1;
        
        vector<pair<int,int>> nextPosition = {
            make_pair(currentPosition.first + a, currentPosition.second + b),
            make_pair(currentPosition.first + a, currentPosition.second - b),
            make_pair(currentPosition.first - a, currentPosition.second + b),
            make_pair(currentPosition.first - a, currentPosition.second - b),
            make_pair(currentPosition.first + b, currentPosition.second + a),
            make_pair(currentPosition.first + b, currentPosition.second - a),
            make_pair(currentPosition.first - b, currentPosition.second + a),
            make_pair(currentPosition.first - b, currentPosition.second - a)
        };
        
        for(int i = 0; i<nextPosition.size(); i++){
            pair<int, int> temp = nextPosition[i];
            int x = temp.first;
            int y = temp.second;
            
            if (x >= 0 && x <= n-1 && y >=0 && y <= n-1){
                if(cache[x][y] > counter){
                    cache[x][y] = counter;
                    que.push(make_pair(x,y));
                }
            }
        }
     }
    
    if (cache[n-1][n-1] == INT_MAX)
        return -1;
    
    return cache[n-1][n-1];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++)
            fout << knightlOnAChessboard(n, i, j) << " ";
        fout << endl;
    }
    fout.close();

    return 0;
}
