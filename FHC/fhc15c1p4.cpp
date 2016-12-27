#include <bits/stdc++.h>

#define MAXN 200001

using namespace std;

int T, N, dp[MAXN][21];
vector<int> adjList[MAXN];

int dfs(int cur, int value){
    if (dp[cur][value] != -1) return dp[cur][value];
    int ans = value;
    for (int i : adjList[cur]){
        int tmp = 1e9;
        for (int k = 1; k < 20; k++){
            if (k == value) continue;
            tmp = min(tmp, dfs(i, k));
        }
        ans += tmp;
    }
    return dp[cur][value] = ans;
}

int main(){
    cin >> T;
    for (int c = 1; c <= T; c++){
        cin >> N;
        for (int i = 0; i < MAXN; i++) adjList[i].clear();
        for (int i = 1, x; i <= N; i++){
            cin >> x;
            if (i != 1){
                adjList[x].push_back(i);
            }
        }
        memset(dp, -1, sizeof dp);
        int ans = 1e9;
        for (int i = 1; i < 20; i++){
            ans = min(ans, dfs(1, i));
        }
        printf("Case #%d: %d\n", c, ans);
    }
}
