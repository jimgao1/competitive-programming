
#include <bits/stdc++.h>

#define MAXN 16
#define MOD 13371337

using namespace std;

inline bool getBit(int n, int idx) { return n & (1 << idx); }
inline int setBit(int n, int idx) { return n | (1 << idx); }

int T, N, paths[MAXN][1 << MAXN];
bool matrix[MAXN][MAXN], contains[MAXN][1 << MAXN];

queue<pair<int, int>> q;

int main(){
    cin >> T;

    while(T--) {
        memset(paths, 0, sizeof paths);
        memset(matrix, 0, sizeof matrix);
        memset(contains, 0, sizeof contains);

        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0, x; j < N; j++) {
                cin >> x;
                matrix[i][j] = x;
            }
        }

        q.push({0, 1});
        paths[0][1] = 1;

        while (!q.empty()) {
            int cur = q.front().first, v = q.front().second;
            q.pop();

            for (int i = 0; i < N; i++) {
                if (!getBit(v, i) && matrix[cur][i]) {
                    paths[i][setBit(v, i)] += paths[cur][v];
                    paths[i][setBit(v, i)] %= MOD;

                    if (!contains[i][setBit(v, i)]) {
                        q.push({i, setBit(v, i)});
                        contains[i][setBit(v, i)] = true;
                    }
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < (1 << MAXN); i++) {
            ans += paths[N - 1][i];
            ans %= MOD;
        }

        cout << ans << endl;
    }
}
