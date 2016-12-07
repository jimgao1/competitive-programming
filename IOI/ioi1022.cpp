#include <bits/stdc++.h>

#define MAXN 1000001
#define INF 0x3f3f3f3f3f3f3f3f
#define ll long long

using namespace std;

int N, id = -1;
ll ans = INF, weight[MAXN], sum[MAXN], dp[MAXN], total = 0;
vector<int> adjList[MAXN];

void dfs(int cur, int pre){
    sum[cur] = weight[cur];
    for (int i : adjList[cur]){
        if (i == pre) continue;
        dfs(i, cur);
        sum[cur] += sum[i];
        dp[cur] = max(dp[cur], sum[i]);
    }

    dp[cur] = max(dp[cur], total - sum[cur]);
}

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &weight[i]);
        total += weight[i];
    }
    for (int i = 0, a, b; i < N - 1; i++){
        scanf("%d%d", &a, &b);
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    dfs(0, -6969);

    for (int i = 0; i < N; i++){
        if (dp[i] < ans){
            ans = dp[i];
            id = i;
        }
    }

    printf("%d\n", id);
}
