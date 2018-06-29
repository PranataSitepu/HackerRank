#include <bits/stdc++.h>
#include <iostream>

#define INF 99999;
using namespace std;

int main()
{
    int road_nodes;
    int road_edges;
    int source, destination, weight;
    int shortestDistance[401][401];
    
    cin >> road_nodes >> road_edges;
    
    for(int i=0; i<=road_nodes; i++){
        for(int j=0; j<=road_nodes; j++){
            if(i==j)
                shortestDistance[i][j]=0;
            else
                shortestDistance[i][j]=INF;
        }
    }
    
    for (int i = 0; i < road_edges; i++) {
        cin >> source >> destination >> weight;
        shortestDistance[source][destination] = weight;
    }
    
    for(int i=0; i<=road_nodes; i++){
        for(int j=0; j<=road_nodes; j++){
            for(int k=0; k<=road_nodes; k++){
                if(shortestDistance[j][i] + shortestDistance[i][k] < shortestDistance[j][k])
                    shortestDistance[j][k] = shortestDistance[j][i]+shortestDistance[i][k];
            }
        }            
    }

    int q;
    cin >> q;

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int x, y;
        cin >> x >> y;
        
        if(shortestDistance[x][y] == 99999)
            cout << "-1" << endl;
        else
            cout << shortestDistance[x][y] << endl;
    }
     
    return 0;
}
