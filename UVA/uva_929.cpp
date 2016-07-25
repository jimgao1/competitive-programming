
#include <bits/stdc++.h>

#define MAXN 1001
#define INF 0x3f3f3f3f
#define state pair<int, pair<int, int>>

using namespace std;

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

int T, R, C, num[MAXN][MAXN], dist[MAXN][MAXN];
priority_queue<state, vector<state>, greater<state>> pq;

int main(){
    cin >> T;
    while(T--) {
        cin >> R >> C;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> num[i][j];
            }
        }

        memset(dist, 0x3f, sizeof dist);

        dist[0][0] = num[0][0];
        pq.push({num[0][0], {0, 0}});
        while (!pq.empty()) {
            int r = pq.top().second.first, c = pq.top().second.second;
            int st = pq.top().first;
            pq.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;

                if (dist[nr][nc] > dist[r][c] + num[nr][nc]) {
                    dist[nr][nc] = dist[r][c] + num[nr][nc];
                    pq.push({dist[nr][nc], {nr, nc}});
                }
            }
        }

        cout << dist[R - 1][C - 1] << endl;
    }
}
