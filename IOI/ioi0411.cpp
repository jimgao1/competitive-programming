
#include <bits/stdc++.h>

#define MAXN 20001
#define INF 0x3f3f3f3f

using namespace std;

int N, x[MAXN], y[MAXN], dp[2][2][2010];

int main(){
    cin >> N;
    x[0] = y[0] = 1000;
    for (int i = 1; i <= N; i++){
        cin >> x[i] >> y[i];
        x[i] += 1000, y[i] += 1000;
    }

    memset(dp, 0x3f, sizeof dp);
    dp[0][0][1000] = dp[0][1][1000] = 0;
    for (int i = 0; i < N; i++){
        int cur = i % 2, nxt = (i + 1) % 2;

        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 2001; k++){
                dp[nxt][j][k] = INF;
            }
        }

        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 2001; k++){
                if (dp[cur][j][k] != INF){
                    int cx, cy;
                    if (j == 0){
                        cx = k, cy = y[i];
                    } else {
                        cx = x[i], cy = k;
                    }

                    dp[nxt][0][cx] = min(dp[nxt][0][cx], dp[cur][j][k] + abs(cy - y[i + 1]));
                    dp[nxt][1][cy] = min(dp[nxt][1][cy], dp[cur][j][k] + abs(cx - x[i + 1]));
                }
            }
        }
    }

    int ans = 1e9;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2001; j++){
            ans = min(ans, dp[N % 2][i][j]);
        }
    }

    cout << ans << endl;
}
