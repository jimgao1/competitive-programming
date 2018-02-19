#include <bits/stdc++.h>

#define MAXN 110
#define pii pair<int, int>

using namespace std;

int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};

int R, C, sr, sc, dist[MAXN][MAXN];
bool visited[MAXN][MAXN], cam[MAXN][MAXN];
char grid[MAXN][MAXN];
priority_queue<pair<int, pii >, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

pii calcNext(int r, int c) {
    memset(visited, 0, sizeof visited);
    while (true) {
        if (grid[r][c] == 'W') return make_pair(-1, -1);
        if (grid[r][c] == '.' || grid[r][c] == 'S' || grid[r][c] == 'C') return make_pair(r, c);
        if (visited[r][c]) return make_pair(-1, -1);
        visited[r][c] = 1;

        if (grid[r][c] == 'L') c--;
        if (grid[r][c] == 'R') c++;
        if (grid[r][c] == 'U') r--;
        if (grid[r][c] == 'D') r++;
    }
}

void updateCam(int r, int c, int dr, int dc) {
    while (true) {
        if (grid[r][c] == 'W') break;
        cam[r][c] = 1;
        r += dr, c += dc;
    }
}

void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    pq.push(make_pair(0, make_pair(sr, sc)));
    dist[sr][sc] = 0;

    if (cam[sr][sc]) return;

    while (!pq.empty()) {
        int r = pq.top().second.first, c = pq.top().second.second;
        pq.pop();

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;

            if (grid[nr][nc] == 'U' || grid[nr][nc] == 'D' || grid[nr][nc] == 'L' || grid[nr][nc] == 'R') {
                pii X = calcNext(nr, nc);
                nr = X.first, nc = X.second;
            }

            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;

            if (cam[nr][nc]) continue;
            if (grid[nr][nc] == 'W') continue;

            if (dist[nr][nc] <= dist[r][c] + 1) continue;
            dist[nr][nc] = dist[r][c] + 1;
            pq.push(make_pair(dist[nr][nc], make_pair(nr, nc)));
        }
    }
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < C; j++) {
            grid[i][j] = line[j];
            if (grid[i][j] == 'S') {
                sr = i, sc = j;
            }
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 'C') {
                for (int k = 0; k < 4; k++)
                    updateCam(i, j, dr[k], dc[k]);
            }
        }
    }

    dijkstra();

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == '.') {
                if (dist[i][j] == 0x3f3f3f3f)
                    printf("-1\n");
                else
                    printf("%d\n", dist[i][j]);
            }
        }
    }
}
