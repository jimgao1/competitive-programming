
#include <bits/stdc++.h>

#define MOD 1000000007
#define ll long long

using namespace std;

int T, N, M, a[201], b[201];
ll dp[201][201];

ll max(ll a, ll b) { return (a > b ? a : b); }

int main(){
    scanf("%d", &T);
    while(T--){
        memset(dp, 0, sizeof dp);

        scanf("%d%d", &N, &M);
        for (int i = 1; i <= N; i++){
            scanf("%d%d", &a[i], &b[i]);
        }

        dp[0][0] = 1;
        for (int i = 1; i <= N; i++){
            for (int j = a[i]; j <= b[i]; j++){
                for (int k = 0; k <= M; k++){
                    if (k - j >= 0){
                        dp[i][k] += dp[i - 1][k - j];
                        dp[i][k] = dp[i][k] % MOD;
                    }
                }
            }
        }

        printf("%lld\n", dp[N][M]);
    }
}

