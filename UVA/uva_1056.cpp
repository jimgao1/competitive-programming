
#include <bits/stdc++.h>

#define MAXN 101
#define INF 0x3f3f3f3f

using namespace std;

int N, M, cnt = 1, dist[MAXN][MAXN];
map<string, int> dict;

int main(){
    while(true) {
        memset(dist, 0x3f, sizeof dist);
        dict.clear();
        int mcnt = 0;

        cin >> N >> M;
        if (N == 0 && M == 0) break;

        cout << "Network " << cnt++ << ": ";

        for (int i = 0; i < N; i++)
            dist[i][i] = 0;

        for (int i = 0; i < M; i++) {
            string sa, sb;
            cin >> sa >> sb;

            if (dict.find(sa) == dict.end()) {
                dict[sa] = mcnt++;
            }
            if (dict.find(sb) == dict.end()) {
                dict[sb] = mcnt++;
            }

            dist[dict[sa]][dict[sb]] = 1;
            dist[dict[sb]][dict[sa]] = 1;
        }

        for (int k = 0; k < N; k++){
            for (int i = 0; i < N; i++){
                for (int j = 0; j < N; j++){
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                ans = max(ans, dist[i][j]);
            }
        }

        if (ans == INF)
            cout << "DISCONNECTED" << endl;
        else
            cout << ans << endl;

        cout << endl;
    }
}
