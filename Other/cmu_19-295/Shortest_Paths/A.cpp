
#include <bits/stdc++.h>

#define MAXN 100005
#define ll long long
#define pii pair<int, int>

using namespace std;

int N, M, pre[MAXN];
ll dist[MAXN];
vector<pii > adjList[MAXN];
priority_queue<pii, vector<pii >, greater<pii>> pq;

void dijkstra(int src) {
    for (int i = 0; i <= N; dist[i++] = 1e18);
    memset(pre, -1, sizeof pre);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();

        for (pii i : adjList[cur]) {
            ll alt = dist[cur] + (ll) i.second;
            if (dist[i.first] > alt) {
                dist[i.first] = alt;
                pre[i.first] = cur;
                pq.push(make_pair(alt, i.first));
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0, a, b, w; i < M; i++) {
        cin >> a >> b >> w;
        a--, b--;
        adjList[a].emplace_back(make_pair(b, w));
        adjList[b].emplace_back(make_pair(a, w));
    }

    dijkstra(0);

    if (dist[N - 1] != 1e18) {
        vector<int> path;
        for (int cur = N - 1; cur != -1; path.push_back(cur), cur = pre[cur]);
        reverse(path.begin(), path.end());

        for (int i : path) printf("%d ", i + 1);
        printf("\n");
    } else {
        printf("-1\n");
    }
}

