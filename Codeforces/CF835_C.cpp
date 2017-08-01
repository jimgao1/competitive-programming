#include <bits/stdc++.h>

using namespace std;

int N, Q, C, sum[20][101][101];

int query(int k, int r1, int c1, int r2, int c2) {
    return sum[k][r2][c2] - sum[k][r2][c1 - 1] - sum[k][r1 - 1][c2] + sum[k][r1 - 1][c1 - 1];
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q >> C;
    C++;
    for (int i = 0, r, c, s; i < N; i++) {
        cin >> r >> c >> s;
        sum[s][r][c]++;
    }

    for (int k = 0; k < C; k++) {
        for (int i = 1; i < 101; i++) {
            for (int j = 1; j < 101; j++) {
                sum[k][i][j] += sum[k][i - 1][j] + sum[k][i][j - 1] - sum[k][i - 1][j - 1];
            }
        }
    }


    for (int i = 0, t, r1, c1, r2, c2; i < Q; i++) {
        cin >> t >> r1 >> c1 >> r2 >> c2;
        int ans = 0;
        for (int k = 0; k < C; k++) {
            int tar = (k + t) % C;
            ans += query(k, r1, c1, r2, c2) * tar;
        }

        cout << ans << "\n";
    }
}
