
#include <bits/stdc++.h>

#define MAXN 210
#define ll long long
#define MOD 1000000007

using namespace std;

int N, W, M;
ll dp[MAXN][MAXN][2];
bool visited[MAXN], in[MAXN];
vector<pair<int, char>> adjList[MAXN];

void dfs(int cur, int parent){
    if (visited[cur]) return;
    visited[cur] = true;

    dp[cur][0][0] = 1;
    dp[cur][1][1] = 1;

    for (pair<int, int> i : adjList[cur]){
        if (i.first == parent) continue;
        dfs(i.first, cur);

        for (int j = W; j >= 0; j--){
            ll ans1 = 0, ans2 = 0;

            for (int k = 0; k <= j; k++){
                //if current is not werewolf
                ans1 += dp[cur][j - k][0] * (dp[i.first][k][0] + dp[i.first][k][1]);

                //if current is werewolf
                if (i.second == 'A'){
                    ans2 += dp[cur][j - k][1] * dp[i.first][k][0];
                } else {
                    ans2 += dp[cur][j - k][1] * dp[i.first][k][1];
                }

                ans1 %= MOD;
                ans2 %= MOD;
            }

            dp[cur][j][0] = ans1;
            dp[cur][j][1] = ans2;
        }
    }
}

int main(){
    cin >> N >> W >> M;
    for (int i = 0, a, b; i < M; i++){
        char op;
        cin >> op >> a >> b;
        in[b] = true;
        adjList[a].push_back({b, op});
    }

    for (int i = 1; i <= N; i++){
        if (!in[i])
            adjList[0].push_back({i, 'A'});
    }

    dfs(0, -1);
    cout << dp[0][W][0] % MOD << endl;
}

