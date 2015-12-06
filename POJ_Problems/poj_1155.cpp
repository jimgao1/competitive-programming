
#include <cstdio>
#include <vector>
#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;

int N, M, dp[3001][3001], p[3001];
vector<pair<int, int> > adjList[3001];

int dfs(int cur){
    for (int i = 1; i <= M; i++)
        dp[cur][i] = -INF;

    if (adjList[cur].size() == 0){
        dp[cur][1] = p[cur];
        return 1;
    }

    int uBound = 0;
    for (int i = 0; i < adjList[cur].size(); i++){
        int v = adjList[cur][i].first;
        int w = adjList[cur][i].second;

        uBound += dfs(v);

        for (int s = uBound; s >= 1; s--){
            for (int k = 0; k <= uBound && k <= s; k++){
                dp[cur][s] = max(dp[cur][s], dp[cur][s - k] + dp[v][k] + w);
            }
        }
    }

    return uBound;
}

int main(){
    scanf("%d%d", &N, &M);

    for (int i = 1, k; i <= N - M; i++){
        scanf("%d", &k);
        for (int j = 0, a, b; j < k; j++){
            scanf("%d%d", &a, &b);
            adjList[i].push_back({a, -1 * b});
        }
    }

    for (int i = N - M + 1; i <= N; i++)
        scanf("%d", &p[i]);

    dfs(1);

    for (int i = M; i >= 0; i--){
        if (dp[1][i] >= 0){
            printf("%d\n", i);
            break;
        }
    }
}
