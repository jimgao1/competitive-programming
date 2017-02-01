
#include <bits/stdc++.h>

#define ll long long
#define MAXN 100001
#define MOD (ll)(1000000007)

using namespace std;

int N, M, in[MAXN];
ll dp[MAXN], ways[MAXN];
bool prec[MAXN], visited[MAXN];
vector<int> adjList[MAXN], order;
queue<int> q;

void dfs(int cur){
    visited[cur] = true;
    for (int i : adjList[cur]){
        if (!visited[i])
            dfs(i);
    }
    order.push_back(cur);
}

int main(){
    cin >> N >> M;
    for (int i = 0, a, b; i < M; i++){
        cin >> a >> b; a--, b--;
        in[b] ++;
        adjList[a].push_back(b);
    }

    for (int i = 0; i < N; i++){
        if (in[i] == 0){
            ways[i] = 1LL;
            dfs(i);
        }
    }

    reverse(order.begin(), order.end());
    for (int cur : order){
        for (int i : adjList[cur]){
            ways[i] = (ways[i] % MOD + ways[cur] % MOD) % MOD;
            dp[i] = (dp[i] % MOD + dp[cur] % MOD + ways[cur] % MOD) % MOD;
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; i++){
        if (adjList[i].size() == 0) {
            ans = (ans + dp[i] % MOD) % MOD;
        }
    }

    cout << ans % MOD << endl;
}

