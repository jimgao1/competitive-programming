
#include <bits/stdc++.h>

#define MAXN 101
#define INF 0x3f3f3f3f

using namespace std;

int T, W, N, coins[MAXN], dp[20000];

int main(){
    cin >> T;
    while(T--){
        memset(dp, 0x3f, sizeof dp);
        memset(coins, 0, sizeof coins);
        cin >> W >> N;
        for (int i = 0; i < N; i++){
            cin >> coins[i];
        }

        dp[0] = 0;
        for (int i = 0; i < N; i++){
            for (int j = 20000; j >= 0; j--){
                if (dp[j] != INF && j + coins[i] <= 20000){
                    dp[j + coins[i]] = min(dp[j + coins[i]], dp[j] + 1);
                }
            }
        }

        for (int i = W; i <= 20000; i++){
            if (dp[i] != INF){
                printf("%d %d\n", i, dp[i]);
                break;
            }
        }
    }
}

