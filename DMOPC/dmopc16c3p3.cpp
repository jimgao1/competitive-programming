#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define MAXN 5100

using namespace std;

int N, M, weight[MAXN], value[MAXN], dp[2][2 * MAXN];

int main(){
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> weight[i] >> value[i];
    memset(dp, -1, sizeof dp);

    int cur = 0;
    dp[cur][M] = 0;

    for (int i = 1; i <= N; i++){
        //for (int j = 0; j <= 10000; j++) dp[1 - cur][j] = -1;

        for (int j = 0; j <= 10000; j++){
            if (dp[cur][j] != -1){
                dp[1 - cur][j] = max(dp[1 - cur][j], dp[cur][j]);
                if (j >= weight[i]){
                    int nxt = j - weight[i] + value[i];
                    if (nxt >= 0 && nxt <= 10000)
                        dp[1 - cur][nxt] = max(dp[1 - cur][nxt], dp[cur][j] + 1);
                }
            }
        }

        cur = 1 - cur;
    }

    int ans1 = 0;
    for (int i = 0; i <= 10000; i++){
        ans1 = max(ans1, dp[cur][i]);
    }

    for (int i = 10000; i >= 0; i--){
        if (dp[cur][i] == ans1){
            cout << ans1 << " " << i << endl;
            break;
        }
    }
}
