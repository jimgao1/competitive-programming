#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define MAXN 20001

using namespace std;

int N, dp[MAXN], parent[MAXN];
vector<int> adjList[MAXN];

void dfs(int cur, int prev){
    dp[cur] = 1;
    parent[cur] = prev;

    for (int i : adjList[cur]){
        if (i != prev){
            dfs(i, cur);
            dp[cur] += dp[i];
        }
    }
}

int main(){
    scanf("%d", &N);
    for (int i = 0, a, b; i < N - 1; i++){
        scanf("%d%d", &a, &b);
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    dfs(1, -1);

    int ans = INF, id = 1;

    for (int i = 1; i <= N; i++){

        int tmp = 0;

        for (int j : adjList[i]){
            if (j != parent[i]){
                tmp = max(tmp, dp[j]);
            }
        }

        tmp = max(tmp, N - dp[i]);

        if (tmp < ans){
            ans = tmp;
            id = i;
        }
    }

    printf("%d %d\n", id, ans);
}
