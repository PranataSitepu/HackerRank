#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char matrix[101][101];
int row, column, wandCount = 0;

bool countLuck(int currentX, int currentY, int prevX=-1, int prevY=-1) {
    const int dx[]={1,-1,0,0};
    const int dy[]={0,0,1,-1};
    int nextX, nextY =0;
    bool flag=0;
    int cc=0;
       
    if (matrix[currentX][currentY] == '*')
        return 1;
    
    for (int i=0; i<4; i++){
        nextX = currentX + dx[i];
        nextY = currentY + dy[i];
        
        if (!(nextX>=0 && nextY>=0 && nextX<column && nextY<row))
            continue;
        
        if (nextX == prevX && nextY == prevY)
            continue;

        if (matrix[nextX][nextY] == 'X')
            continue;
        
        if (countLuck(nextX, nextY, currentX, currentY))
            flag = 1;
        cc++;
    }
    if (flag==1 && cc>1)
        wandCount++;
    
    return flag;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    string result;
    int x, y = 0;
    
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        cin >> column >> row;
        
        for (int i=0; i<column; i++){
            for (int j=0; j<row; j++){
                cin >> matrix[i][j];
                
                if (matrix[i][j] == 'M'){
                    x = i;
                    y = j;    
                }
            }
        }
        
        int k;
        cin >> k;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        wandCount = 0;
        
        countLuck(x, y);
        if(wandCount == k)
            result = "Impressed";
        else
            result = "Oops!";

        fout << result << "\n";
    }

    fout.close();

    return 0;
}