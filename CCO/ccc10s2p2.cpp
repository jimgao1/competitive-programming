
#include <bits/stdc++.h>

#define MAXN 301
#define INF 0x3f3f3f3f

using namespace std;

int N, D, color[MAXN], dp[MAXN][MAXN * 2 + 100];
vector<int> adjList[MAXN];

void dfs(int cur){
    if (adjList[cur].size() == 0){
        dp[cur][color[cur] + MAXN] = 0;
        dp[cur][0 + MAXN] = 1;
    } else if (adjList[cur].size() == 1){
        int c = adjList[cur][0];
        dfs(c);
        dp[cur][0 + MAXN] = 1;
        for (int i = -MAXN; i <= MAXN; i++){
            if (dp[c][i - color[cur] + MAXN] != INF){
                dp[cur][i + MAXN] = min(dp[cur][i + MAXN], dp[c][i - color[cur] + MAXN]);
            }
        }
    } else {
        dp[cur][0 + MAXN] = 1;
        int a = adjList[cur][0], b = adjList[cur][1];
        dfs(a);
        dfs(b);
        for (int i = -MAXN; i <= MAXN; i++){
            int tar = i - color[cur];
            for (int j = -MAXN; j <= MAXN; j++){
                int k = tar - j;

                if (dp[a][j + MAXN] != INF && dp[b][k + MAXN] != INF){
                    dp[cur][i + MAXN] = min(dp[cur][i + MAXN], dp[a][j + MAXN] + dp[b][k + MAXN]);
                }
            }
        }
    }
}

int main(){
    cin >> N >> D;
    for (int i = 0; i < N; i++){
        int id, col, x;
        cin >> id >> col >> x;
        color[id] = -1 + 2 * col;
        for (int j = 0, xx; j < x; j++){
            cin >> xx;
            adjList[id].push_back(xx);
        }
    }

    memset(dp, 0x3f, sizeof dp);
    dfs(0);

    if (dp[0][D + MAXN] >= INF)
        cout << "-1" << endl;
    else
        cout << dp[0][D + MAXN] << endl;
}

