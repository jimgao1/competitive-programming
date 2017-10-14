
#include <bits/stdc++.h>

#define MAXN 5001
#define ll long long

using namespace std;

int N, H;
ll h[MAXN], g[MAXN], t[MAXN], q[MAXN];
ll dp[2][MAXN];
bool used[MAXN];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> H;
    for (int i = 1; i <= N; i++) cin >> g[i] >> h[i] >> q[i] >> t[i];

    for (int i = 1; i <= N; i++) {
        int a = i % 2, b = (i + 1) % 2;

        for (int j = 0; j <= H; j++) dp[a][j] = 0;
        memset(used, 0, sizeof used);

        for (int j = 0; j <= H; j++) {
            if (j >= h[i]) {
                dp[a][j] = dp[b][j - h[i]] + g[i];
                used[j] = 1;
            }
        }

        for (int j = 0; j <= H; j++) {
            if (j >= t[i] && used[j - t[i]]) {
                dp[a][j] = max(dp[a][j], dp[a][j - t[i]] + q[i]);
            }
        }

        for (int j = 0; j <= H; j++) dp[a][j] = max(dp[a][j], dp[b][j]);
    }

    ll ans = 0;
    for (int i = 0; i <= H; i++) {
        ans = max(ans, dp[N % 2][i]);
    }

    cout << ans << "\n";
}
