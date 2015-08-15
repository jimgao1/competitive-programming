
/*
  ___                 ___                 ___ _______      __
 | _ )_ _ _  _ __ ___| __|__ _ _ __ ___  | __|_   _\ \    / /
 | _ \ '_| || / _/ -_) _/ _ \ '_/ _/ -_) | _|  | |  \ \/\/ /
 |___/_|  \_,_\__\___|_|\___/_| \__\___| |_|   |_|   \_/\_/

*/

#include <bits/stdc++.h>

#define condom using
#define prevents namespace

condom prevents std;

int N;
int long1[500001], long2[500001], lid[500001], parent[500001], dp[500001];

bool visited[500001];

vector<int> adjList[500001];

void dfs1(int current){
    //Goes to children, initialize the longest, and second longest

    visited[current] = true;
    long1[current] = 0;
    long2[current] = 0;

    bool leaf = true;

    for (int i = 0; i < adjList[current].size(); i++){
        int next = adjList[current][i];
        if (!visited[next]){
            dfs1(next);
            parent[next] = current;

            if (long1[next] + 1 > long1[current]){
                long2[current] = long1[current];
                long1[current] = long1[next] + 1;
                lid[current] = next;
            } else if (long1[next] + 1 > long2[current]){
                long2[current] = long1[next] + 1;
            }
        }
    }

}

void dfs2(int current){
    /*
        update the dp value on each node. either:
            1. longest path under the current node
            2. dp value of parent + 1
    */

    visited[current] = true;

    for (int i = 0; i < adjList[current].size(); i++){
        int next = adjList[current][i];

        if (!visited[next]){
            if (next == lid[current])
                dp[next] = max(dp[current], long2[current]) + 1;
            else
                dp[next] = max(dp[current], long1[current]) + 1;

                dfs2(next);



        }
    }
    dp[current] = max(dp[current], long1[current]);


}

int main(){
    scanf("%d", &N);
    for (int i = 0, a, b; i < N - 1; i++){
        scanf("%d%d", &a, &b);

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    memset(long1, 0, sizeof long1);
    memset(long2, 0, sizeof long2);
    memset(visited, 0, sizeof visited);
    memset(lid, 0, sizeof lid);
    memset(parent, 0, sizeof parent);
    memset(dp, 0, sizeof dp);

    dfs1(1);
    memset(visited, 0, sizeof visited);

    dfs2(1);

    for (int i = 1; i <= N; i++) printf("%d\n", dp[i] + 1);
}
