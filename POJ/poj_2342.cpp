/*
    FUCKING POJ DOESN'T SUPPORT RANGE-BASED FOR LOOPS :( .!..
*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

#define INF 0x3f3f3f3f

using namespace std;

int N, ans = 0, p[6001], parent[6001], dp[6001][2];
vector<int> adjList[6001];

void dfs(int cur){
    for (int i = 0; i < adjList[cur].size(); i++)
        dfs(adjList[cur][i]);

    dp[cur][1] = p[cur];
    for (int i = 0; i < adjList[cur].size(); i++)
        dp[cur][1] += dp[adjList[cur][i]][0];

    dp[cur][0] = 0;
    for (int i = 0; i < adjList[cur].size(); i++)
        dp[cur][0] += max(dp[adjList[cur][i]][0], dp[adjList[cur][i]][1]);
}

int main(){
    memset(parent, 0x3f, sizeof parent);

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &p[i]);

    while(true){
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 0 && b == 0) break;

        adjList[b - 1].push_back(a - 1);
        parent[a - 1] = b - 1;
    }

    for (int i = 0; i < N; i++){
        if (parent[i] == INF) dfs(i);
    }

    for (int i = 0; i < N; i++)
        ans = max(ans, max(dp[i][0], dp[i][1]));

    printf("%d\n", ans);
}
