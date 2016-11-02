
#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

struct pipe{
    int src, tar, flow;
    bool super;

    pipe(int a, int b, int c, bool d){
        src = a, tar = b, flow = c, super = d;
    }
};

int N, K[MAXN];
bool noroot[MAXN], matrix[MAXN][MAXN], magic[MAXN][MAXN];
double dp[MAXN], flow[MAXN][MAXN];

void dfs(int cur, int parent){
    if (K[cur] != -1){
        dp[cur] = (double)(K[cur]);
        return;
    }

    for (int i = 0; i < N; i++){
        if (matrix[cur][i] && i != parent){
            dfs(i, cur);

            double req = dp[i] / flow[cur][i];
            if (magic[cur][i])
                req = min(req, sqrt(dp[i]) / flow[cur][i]);

            dp[cur] = max(dp[cur], req);
        }
    }
}

int main(){
    cin >> N;
    for (int i = 0, a, b, x, t; i < N - 1; i++){
        cin >> a >> b >> x >> t;
        a--, b--;

        matrix[a][b] = true;
        magic[a][b] = (t == 1);
        flow[a][b] = (x / 100.0);

        noroot[b] = true;
    }

    for (int i = 0; i < N; i++){
        cin >> K[i];
    }

    for (int i = 0; i < N; i++){
        if (!noroot[i]){
            dfs(i, -1);
            printf("%.4f\n", dp[i]);
            break;
        }
    }
}

