
#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};

int T, R, C, dist[MAXN][MAXN];
char grid[MAXN][MAXN];
deque<pair<int, pair<int, int>>> q;

void solve() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < C; j++) {
            grid[i][j] = str[j];
        }
    }

    while (!q.empty()) q.pop_front();
    q.push_front(make_pair(0, make_pair(0, 0)));
    memset(dist, 0x3f, sizeof dist);

    while (!q.empty()) {
        int r, c, cost = q.front().first;
        tie(r, c) = q.front().second;
        q.pop_front();

        if (r == R - 1 && c == C - 1) {
            printf("%d\n", cost);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;

            int alt = cost + (grid[nr][nc] == grid[r][c] ? 0 : 1);
            if (dist[nr][nc] > alt) {
                dist[nr][nc] = alt;
                if (grid[nr][nc] == grid[r][c]) {
                    q.push_front(make_pair(alt, make_pair(nr, nc)));
                } else {
                    q.push_back(make_pair(alt, make_pair(nr, nc)));
                }
            }
        }
    }
}

int main() {
    cin >> T;
    while (T--) {
        solve();
    }
}
