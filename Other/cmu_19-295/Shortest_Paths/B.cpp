
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

string S, T;
int N, dist[30][30];

int main() {
    cin >> S >> T;
    cin >> N;

    memset(dist, 0x3f, sizeof dist);

    for (int i = 0; i < 26; i++) dist[i][i] = 0;

    for (int i = 0; i < N; i++) {
        char a, b;
        int w;
        cin >> a >> b >> w;
        dist[a - 'a'][b - 'a'] = min(dist[a - 'a'][b - 'a'], w);
    }

    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    if (S.length() != T.length()) {
        cout << -1 << endl;
        return 0;
    }

    int cost = 0;

    for (int i = 0; i < S.length(); i++) {
        if (S[i] != T[i]) {
            int tmp = INF, val;
            for (int j = 0; j < 26; j++) {
                if (dist[S[i] - 'a'][j] != INF && dist[T[i] - 'a'][j] != INF) {
                    int tmpDist = dist[S[i] - 'a'][j] + dist[T[i] - 'a'][j];
                    if (tmpDist < tmp) {
                        tmp = tmpDist;
                        val = j;
                    }
                }
            }

            if (tmp == INF) {
                cout << -1 << endl;
                return 0;
            }

            cost += tmp;
            S[i] = val + 'a';
        }
    }

    cout << cost << endl;
    cout << S << endl;
}
