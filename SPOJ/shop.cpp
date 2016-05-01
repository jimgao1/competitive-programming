
#include <bits/stdc++.h>

#define MAXN 30
#define state tuple<int, int, int>

using namespace std;

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

int R, C, grid[MAXN][MAXN], dist[MAXN][MAXN];
pair<int, int> dst;
priority_queue<state, vector<state>, greater<state>> pq;

int main() {
    while(true) {
        memset(dist, 0x3f, sizeof dist);
        memset(grid, 0, sizeof grid);
        while(!pq.empty()) pq.pop();

        cin >> C >> R;

        if (C == 0 && R == 0) break;
        for (int i = 0; i < R; i++) {
            string line;
            cin >> line;

            for (int j = 0; j < C; j++) {
                if (line[j] == 'X') {
                    grid[i][j] = -1;
                } else if (line[j] == 'S') {
                    dist[i][j] = 0;
                    pq.push(make_tuple(0, i, j));
                } else if (line[j] == 'D') {
                    dst = {i, j};
                } else {
                    grid[i][j] = line[j] - '0';
                }
            }
        }

        while (!pq.empty()) {
            int cr = get<1>(pq.top()), cc = get<2>(pq.top()), st = get<0>(pq.top());
            pq.pop();

            //printf("cr = %d, cc = %d, st = %d\n", cr, cc, st);

            if (cr == dst.first && cc == dst.second) continue;
            if (grid[cr][cc] == -1) continue;

            for (int i = 0; i < 4; i++) {
                int nr = cr + dx[i], nc = cc + dy[i];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
                if (grid[nr][nc] == -1) continue;

                if (dist[cr][cc] + grid[nr][nc] < dist[nr][nc]) {
                    dist[nr][nc] = dist[cr][cc] + grid[nr][nc];
                    pq.push(make_tuple(dist[nr][nc], nr, nc));
                }
            }
        }

        cout << dist[dst.first][dst.second] << endl;
    }
}
