
#include <bits/stdc++.h>

using namespace std;

int N, W, v[101], w[101], dp[101][101];

int main(){
    memset(dp, 0, sizeof dp);
    memset(v, 0, sizeof v);
    memset(w, 0, sizeof w);

    scanf("%d%d", &N, &W);
    for (int i = 1; i <= N; i++) scanf("%d%d", &v[i], &w[i]);

    for (int i = 1; i <= N; i++){
        for (int j = 0; j <= W; j++){
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (w[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }

    for (int i = 0; i <= N; i++){
        for (int j = 0; j <= W; j++)
            printf("%d\t", dp[i][j]);
        printf("\n");
    }
}
