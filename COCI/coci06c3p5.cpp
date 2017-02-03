
#include <bits/stdc++.h>

#define MAXN 10001
#define ll long long
#define MOD 1000000000LL

using namespace std;

int N, M;
ll dp[MAXN];
bool visited[MAXN];
vector<int> adjList[MAXN], order;

void dfs(int cur){
    visited[cur] = 1;
    for (int i : adjList[cur]){
        if (!visited[i]){
            dfs(i);
        }
    }
    order.push_back(cur);
}

int main(){
    cin >> N >> M;
    for (int i = 0, a, b; i < M; i++){
        cin >> a >> b;
        a--, b--;
        adjList[a].push_back(b);
    }

    dfs(0);
    reverse(order.begin(), order.end());
    memset(visited, 0, sizeof visited);

    dp[0] = 1LL;
    bool flag = false, display = false;
    for (int cur : order){
        for (int i : adjList[cur]){
            dp[i] += dp[cur];
            if (dp[i] >= MOD) {
                display = 1;
                dp[i] = dp[i] % MOD;
            }

            if (visited[i]){
                flag = true;
                break;
            }
        }
        visited[cur] = true;
    }

    if (dp[1] >= MOD || display)
        printf("%09d\n", (int)(dp[1] % MOD));
    else
        printf("%d\n", dp[1]);
}
