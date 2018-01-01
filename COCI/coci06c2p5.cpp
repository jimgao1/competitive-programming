
#include <bits/stdc++.h>

#define MAXN 410

using namespace std;

int R, C, sum[MAXN][MAXN];

int calcSum(int r1, int c1, int r2, int c2) {
    return sum[r2][c2] - sum[r1 - 1][c2] - sum[r2][c1 - 1] + sum[r1 - 1][c1 - 1];
}

int main() {
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= C; j++) {
            if (str[j - 1] == 'X') sum[i][j] = 1;
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    int ans = 0;
    for (int r = 1; r <= R; r++) {
        for (int c = 1; c <= C; c++) {
            for (int r2 = r; r2 <= R; r2++) {
                if (calcSum(r, c, r2, c) > 0) continue;
                int low = c, high = C;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (calcSum(r, c, r2, mid) > 0) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                        ans = max(ans, 2 * ((r2 - r + 1) + (mid - c + 1)));
                    }
                }
            }
        }
    }

    cout << ans - 1 << endl;
}
