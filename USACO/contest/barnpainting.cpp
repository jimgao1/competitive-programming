
#include <bits/stdc++.h>

#define MAXN 100005
#define MOD 1000000007

#define ll long long

using namespace std;

int N, K, color[MAXN];
ll dp[MAXN][3];
bool colored[MAXN];
vector<int> adjList[MAXN];

ll dfs(int cur, int cc, int pre) {
    if (colored[cur] && color[cur] != cc) return 0;
    if (dp[cur][cc] != -1) return dp[cur][cc];
    color[cur] = cc;

    ll ans = 1;
    for (int i : adjList[cur]) {
        if (i == pre) continue;
        ll tmp = 0;

        if (colored[i]) {
            if (color[i] != cc)
                tmp = (tmp + dfs(i, color[i], cur)) % MOD;
        } else {
            for (int j = 0; j < 3; j++) {
                if (j != cc)
                    tmp = (tmp + dfs(i, j, cur)) % MOD;
            }
        }

        ans = (ans * tmp) % MOD;
    }

    return dp[cur][cc] = ans;
}

int main() {
    freopen("barnpainting.in", "r", stdin);
    freopen("barnpainting.out", "w", stdout);

    memset(dp, -1, sizeof dp);

    cin >> N >> K;
    for (int i = 0, a, b; i < N - 1; i++) {
        cin >> a >> b;
        a--, b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    for (int i = 0, a, b; i < K; i++) {
        cin >> a >> b;
        a--;
        color[a] = b - 1;
        colored[a] = 1;
    }

    if (colored[0]) {
        cout << dfs(0, color[0], -1) % MOD << endl;
    } else {
        ll ans = 0;
        for (int i = 0; i < 3; i++) {
            ans = (ans + dfs(0, i, -1)) % MOD;
        }
        cout << ans << endl;
    }
}
