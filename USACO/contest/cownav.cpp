
#include <bits/stdc++.h>

#define MAXN 21

using namespace std;

int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};

struct state {
    int cost;
    pair<int, int> a, b, dir;

    state(pair<int, int> _, pair<int, int> __, pair<int, int> ___, int ____) {
        a.first = _.first, a.second = _.second;
        b.first = __.first, b.second = __.second;
        dir.first = ___.first, dir.second = ___.second;
        cost = ____;
    }
};

int N, dist[MAXN][MAXN][MAXN][MAXN][4][4];
bool blocked[MAXN][MAXN];
queue<state> q;

pair<int, int> go(pair<int, int> cur, int dr, int dc) {
    int nr = cur.first + dr, nc = cur.second + dc;
    if (nr < 0 || nr >= N || nc < 0 || nc >= N) return cur;
    if (blocked[nr][nc]) return cur;
    if (cur == make_pair(0, N - 1)) return cur;
    return pair<int, int>(nr, nc);
}

int main() {
    freopen("cownav.in", "r", stdin);
    freopen("cownav.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++) {
            if (str[j] == 'H') blocked[i][j] = true;
        }
    }

    state init(make_pair(N - 1, 0), make_pair(N - 1, 0), make_pair(0, 1), 0);

    memset(dist, 0x3f, sizeof dist);
    q.push(init);

    while (!q.empty()) {
        state cur = q.front();
        q.pop();

        if (cur.a == make_pair(0, N - 1) && cur.b == make_pair(0, N - 1)) {
            cout << cur.cost << endl;
            return 0;
        }

        if (dist[cur.a.first][cur.a.second][cur.b.first][cur.b.second][cur.dir.first][cur.dir.second] <=
            cur.cost)
            continue;
        dist[cur.a.first][cur.a.second][cur.b.first][cur.b.second][cur.dir.first][cur.dir.second] = cur.cost;



        q.push(state(go(cur.a, dr[cur.dir.first], dc[cur.dir.first]), go(cur.b, dr[cur.dir.second], dc[cur.dir.second]),
                     cur.dir, cur.cost + 1));

        q.push(state(cur.a, cur.b, make_pair((cur.dir.first + 1) % 4, (cur.dir.second + 1) % 4), cur.cost + 1));
        q.push(state(cur.a, cur.b, make_pair((cur.dir.first + 3) % 4, (cur.dir.second + 3) % 4), cur.cost + 1));
    }
}
