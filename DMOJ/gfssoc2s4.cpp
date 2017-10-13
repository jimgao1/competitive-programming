#include <bits/stdc++.h>

#define MAXN 500050
#define pii pair<int, int>

using namespace std;

int N, M, D, dist[2][MAXN];
vector<pii > adj[2][MAXN];
priority_queue<pii, vector<pii >, greater<pii>> pq;

void dijkstra(int src, int id) {
    dist[id][src] = 0;
    while (!pq.empty()) pq.pop();

    pq.push(make_pair(0, src));
    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();

        for (pii i : adj[id][cur]) {
            int alt = dist[id][cur] + i.second;
            if (alt < dist[id][i.first]) {
                dist[id][i.first] = alt;
                pq.push(make_pair(alt, i.first));
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    memset(dist, 0x3f, sizeof dist);

    cin >> N >> M;
    for (int i = 0, a, b, w; i < M; i++) {
        cin >> a >> b >> w;
        a--, b--;
        adj[0][a].push_back(make_pair(b, w));
        adj[1][b].push_back(make_pair(a, w));
    }

    dijkstra(0, 0);
    dijkstra(N - 1, 1);

    int ans = dist[0][N - 1];

    cin >> D;
    for (int i = 0, a, b, w; i < D; i++) {
        cin >> a >> b >> w;
        a--, b--;

        ans = min(ans, w + dist[0][a] + dist[1][b]);
    }

    cout << (ans == 0x3f3f3f3f ? -1 : ans) << "\n";
}
