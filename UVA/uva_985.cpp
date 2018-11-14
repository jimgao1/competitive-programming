
#include <bits/stdc++.h>

#define MAXN 501

using namespace std;

inline bool getBit(int n, int idx) { return n & (1 << idx); }
inline int setBit(int n, int idx) { return n | (1 << idx); }

struct state {
    int r, c, steps;
    state(int x, int y, int z) {
        r = x;
        c = y;
        steps = z;
    }
};

int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};
int R, C, grid[MAXN][MAXN];
bool visited[MAXN][MAXN][4];
queue<state> q;

void solve() {
    memset(grid, 0, sizeof grid);
    memset(visited, 0, sizeof visited);
    while (!q.empty()) q.pop();

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (i == R - 1 && j == C - 1) break;

            string str;
            cin >> str;
            for (char c : str) {
                if (c == 'N') grid[i][j] |= (1 << 0);
                if (c == 'E') grid[i][j] |= (1 << 1);
                if (c == 'S') grid[i][j] |= (1 << 2);
                if (c == 'W') grid[i][j] |= (1 << 3);
            }
        }
    }

    q.push(state(0, 0, 0));
    while (!q.empty()) {
        state cur = q.front();
        q.pop();

        if (cur.r < 0 || cur.r >= R || cur.c < 0 || cur.c >= C) continue;

        if (visited[cur.r][cur.c][cur.steps % 4]) continue;
        visited[cur.r][cur.c][cur.steps % 4] = true;

        if (cur.r == R - 1 && cur.c == C - 1) {
            printf("%d\n", cur.steps);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int check = (i - cur.steps % 4 + 4) % 4;
            if (grid[cur.r][cur.c] & (1 << check)) {
                q.push(state(cur.r + dr[i], cur.c + dc[i], cur.steps + 1));
            }
        }
    }

    printf("no path to exit\n");
}

int main() {
    while (cin >> R) {
        cin >> C;
        solve();
    }
}
