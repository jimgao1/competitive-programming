/*
ID: jim.yub1
LANG: C++11
TASK: agrinet
*/

#include <bits/stdc++.h>

using namespace std;

int nodeCount;
int matrix[110][110];

bool visited[110];

int main(){
    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);

    cin >> nodeCount;

    for (int i=0; i<nodeCount; i++)
        for (int j=0; j<nodeCount; j++)
        cin >> matrix[i][j];

    memset(visited, false, sizeof(visited));

    int t = 0;
    visited[0] = true;


    while(true){

        bool vis = true;
        for (int i=0; i<nodeCount; i++)
            vis = vis & visited[i];

        if (vis) break;

        int src, tar, minw = 1000000;
        for (int i=0; i<nodeCount; i++){
            if (visited[i]){
                for (int j=0; j<nodeCount; j++){
                    if (i != j && !visited[j] && minw > matrix[i][j]){
                        src = i, tar = j, minw = matrix[i][j];
                    }
                }
            }
        }

        //cout << "src = " << src << ", tar = " << tar << ", minw = " << minw << endl;

        visited[tar] = true;
        t += minw;
    }

    cout << t << endl;
    return 0;
}
