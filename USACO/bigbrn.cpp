
#include <bits/stdc++.h>

#define MAXN 1003

using namespace std;

int N, T, dp[MAXN][MAXN];

void fuckit() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }
}

int getfuck(int r1, int c1, int w, int h) {
    int r2 = r1 + w - 1, c2 = c1 + h - 1;
    return dp[r2][c2] - dp[r2][c1 - 1] - dp[r1 - 1][c2] + dp[r1 - 1][c1 - 1];
}

int main() {
    cin >> N >> T;
    for (int i = 0, x, y; i < T; i++) {
        cin >> x >> y;
        dp[x][y]++;
    }

    fuckit();

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int low = 1, high = min(N - i + 1, N - j + 1), t = 0;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (getfuck(i, j, mid, mid) == 0){
                    low = mid + 1;
                    t = max(t, mid);
                } else {
                    high = mid - 1;
                }
            }

            ans = max(ans, t);
        }
    }

    cout << ans << endl;
}

