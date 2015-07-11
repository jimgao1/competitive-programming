
#include <bits/stdc++.h>

using namespace std;

int C, M, n[1001], k[1001], dp[1001][1001];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> C >> M;
    for (int i = 1; i <= C; i++) cin >> n[i] >> k[i];

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= C; i++){
        for (int j = 0; j <= M; j++){
            if (j - k[i] < 0){
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - k[i]] + n[i]);
            }
        }
    }

    int p = 0;

    for (int i = 0; i <= M; i++)
        p = max(p, dp[C][i]);

    cout << p << "\n";
}
