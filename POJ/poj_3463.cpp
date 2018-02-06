
#include <iostream>
#include <vector>
#include <cstring>

#define MAXN 2001
#define INF 0x3f3f3f3f
#define pii pair<int, int>

using namespace std;

int K, N, M, S, T, dist[MAXN][2], ways[MAXN][2];
bool visited[MAXN][2];
vector<pii > adjList[MAXN];

void init() {
    memset(dist, 0x3f, sizeof dist);
    memset(ways, 0, sizeof ways);
    memset(visited, 0, sizeof visited);
    for (int i = 0; i < MAXN; i++) adjList[i].clear();
}

void dijkstra(int src) {
    dist[src][0] = 0, ways[src][0] = 1;

    for (int i = 0; i < N * 2 + 1; i++) {
        int cur = -1, dst = INF, flag = 0;
        for (int j = 0; j < N; j++) {
            if (!visited[j][0] && dist[j][0] < dst) {
                cur = j, dst = dist[j][0], flag = 0;
            } else if (!visited[j][1] && dist[j][1] < dst) {
                cur = j, dst = dist[j][1], flag = 1;
            }
        }

        if (cur == -1) break;
        visited[cur][flag] = 1;

        for (int j = 0; j < adjList[cur].size(); j++) {
            pii c = adjList[cur][j];

            int alt = dst + c.second;

            if (alt < dist[c.first][0]) {
                dist[c.first][1] = dist[c.first][0], ways[c.first][1] = ways[c.first][0];
                dist[c.first][0] = alt, ways[c.first][0] = ways[cur][flag];
            } else if (alt == dist[c.first][0]) {
                ways[c.first][0] += ways[cur][flag];
            } else if (alt < dist[c.first][1]) {
                dist[c.first][1] = alt, ways[c.first][1] = ways[cur][flag];
            } else if (alt == dist[c.first][1]) {
                ways[c.first][1] += ways[cur][flag];
            }
        }
    }
}

void solve() {
    cin >> N >> M;
    for (int i = 0, a, b, w; i < M; i++) {
        cin >> a >> b >> w;
        a--, b--;
        adjList[a].push_back(make_pair(b, w));
    }

    cin >> S >> T;
    S--, T--;

    dijkstra(S);

    if (dist[T][1] == dist[T][0] + 1) {
        cout << ways[T][0] + ways[T][1] << "\n";
    } else {
        cout << ways[T][0] << "\n";
    }
}

int main() {
    cin >> K;
    while (K--) {
        init();
        solve();
    }
}
