
#include <bits/stdc++.h>

#define MAXN 2600

using namespace std;

int N, M, K, T, diff[MAXN][MAXN], bit[100005];
double dodoed[MAXN][MAXN];
vector<pair<int, int>> loc;

int popcount(int n) {
    int c = 0;
    for (int i = 0; i < 6; i++) {
        if (n & (1 << i)) c++;
    }
    return c;
}

int query(int i) {
    int a = 0;
    i += 2;
    while (i <= 100004) {
        a += bit[i];
        i += (i & -i);
    }
    return a;
}

void update(int i, int v) {
    i += 2;
    while (i > 0) {
        bit[i] += v;
        i -= (i & -i);
    }
}

int main() {
    cin >> N >> K;

    cin >> M;
    for (int i = 0, cnt; i < M; i++) {
        cin >> cnt;
        loc.clear();

        for (int j = 0, r, c; j < cnt; j++) {
            cin >> r >> c;
            loc.push_back(make_pair(r - 1, c - 1));
        }

        for (int j = 1; j < (1 << cnt); j++) {
            int r1 = 0, c1 = 0, r2 = N - 1, c2 = N - 1;
            for (int k = 0; k < cnt; k++) {
                if (j & (1 << k)) {
                    r1 = max(r1, loc[k].first - K + 1);
                    r2 = min(r2, loc[k].first);
                    c1 = max(c1, loc[k].second - K + 1);
                    c2 = min(c2, loc[k].second);
                }
            }

            if (r2 >= r1 && c2 >= c1) {
                int f = (popcount(j) & 1) * 2 - 1;

                diff[r1][c1] += f;
                diff[r1][c2 + 1] -= f;
                diff[r2 + 1][c1] -= f;
                diff[r2 + 1][c2 + 1] += f;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i > 0) diff[i][j] += diff[i - 1][j];
            if (j > 0) diff[i][j] += diff[i][j - 1];
            if (i > 0 && j > 0) diff[i][j] -= diff[i - 1][j - 1];
        }
    }

    for (int i = 0; i <= N - K; i++) {
        for (int j = 0; j <= N - K; j++) {
            update(diff[i][j], 1);
        }
    }

    long double t = pow(N - K + 1, 2.0);

    cin >> T;
    while (T--) {
        int cmd, a, b, v;
        cin >> cmd;

        if (cmd == 1) {
            cin >> a >> b;
            a--, b--;

            for (int r = max(0, a - K + 1); r <= min(N - K, a); r++) {
                for (int c = max(0, b - K + 1); c <= min(N - K, b); c++) {
                    if (!dodoed[r][c])
                        update(diff[r][c], -1);
                    dodoed[r][c] = 1;
                }
            }
        } else {
            cin >> v;
            if (v > M) {
                cout << "0.000000000" << endl;
            } else {
                cout << fixed << setprecision(8) << ((long double) (query(v)) / t) << endl;
            }
        }
    }
}
