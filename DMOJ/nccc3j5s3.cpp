#include <bits/stdc++.h>

#define ld long double
#define EPS (1e-6)

using namespace std;

int N;
vector<pair<ld, ld>> P;

vector<ld> gauss(ld A[2][3]) {
    int n = 2;

    for (int i = 0; i < n; i++) {
        ld maxEl = abs(A[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(A[k][i]) > maxEl) {
                maxEl = abs(A[k][i]);
                maxRow = k;
            }
        }

        for (int k = i; k < n + 1; k++) {
            ld tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        }

        for (int k = i + 1; k < n; k++) {
            ld c = -A[k][i] / A[i][i];
            for (int j = i; j < n + 1; j++) {
                if (i == j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] += c * A[i][j];
                }
            }
        }
    }

    vector<ld> x(n);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = A[i][n] / A[i][i];
        for (int k = i - 1; k >= 0; k--) {
            A[k][n] -= A[k][i] * x[i];
        }
    }
    return x;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        ld x, y;
        cin >> x >> y;
        P.push_back(make_pair(x, y));
    }

    sort(P.begin(), P.end());
    P.erase(unique(P.begin(), P.end()), P.end());

    N = P.size();

    ld ans = 1e20;

    if (N == 1) ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                ld A[2][3] = {
                        {
                                2 * P[i].first - 2 * P[j].first,
                                2 * P[i].second - 2 * P[j].second,
                                pow(P[i].first, 2) + pow(P[i].second, 2) - pow(P[j].first, 2) - pow(P[j].second, 2)
                        },
                        {
                                2 * P[j].first - 2 * P[k].first,
                                2 * P[j].second - 2 * P[k].second,
                                pow(P[j].first, 2) + pow(P[j].second, 2) - pow(P[k].first, 2) - pow(P[k].second, 2)
                        }
                };

                vector<ld> S = gauss(A);
                ld X = S[0], Y = S[1];

                ld R2 = pow(P[i].first - X, 2) + pow(P[i].second - Y, 2);
                bool flag = true;

                for (int a = 0; a < N; a++) {
                    ld D = pow(P[a].first - X, 2) + pow(P[a].second - Y, 2);
                    if (D > R2 + EPS) {
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    ans = min(ans, sqrt(R2));
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ld X = (P[i].first + P[j].first) / 2, Y = (P[i].second + P[j].second) / 2;
            ld R2 = pow(P[i].first - X, 2) + pow(P[i].second - Y, 2);

            bool flag = true;
            for (int k = 0; k < N; k++) {
                ld D = pow(P[k].first - X, 2) + pow(P[k].second - Y, 2);
                if (D > R2 + EPS) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                ans = min(ans, sqrt(R2));
            }
        }
    }

    cout << fixed << setprecision(12) << ans << endl;
}
