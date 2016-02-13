#include <bits/stdc++.h>

using namespace std;

int T, N, K, W, pins[30001], sum[30001], dp[501][30001];

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &N, &K, &W);

        memset(sum, 0, sizeof sum);
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < N; i++) scanf("%d", &pins[i]);

        for (int i = 0; i < N; i++){
            for (int j = 0; j < W && i - j >= 0; j++){
                sum[i] += pins[i - j];
            }
        }

        for (int i = 1; i <= K; i++) dp[i][0] = pins[0];

        for (int i = 1; i <= K; i++){
            for (int j = 1; j < N; j++){
                int tmp = sum[j];
                if (j - W >= 0){
                    tmp += dp[i - 1][j - W];
                }

                dp[i][j] = max(tmp, dp[i][j - 1]);
            }
        }

        cout << dp[K][N - 1] << endl;
    }
}
