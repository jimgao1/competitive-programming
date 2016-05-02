
#include <bits/stdc++.h>

#define MAXN 20001
#define pii pair<int, int>
#define INF 0x3f3f3f3f

using namespace std;

int tcases, N, M, S, T, dist[MAXN];
vector<pair<int, int> > adjList[MAXN];
priority_queue<pii, vector<pii>, greater<pii> > pq;

void dijkstra(int src){
    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        int cur = pq.top().second, st = pq.top().first;
        pq.pop();

        for (auto n : adjList[cur]){
            if (dist[n.first] > dist[cur] + n.second){
                dist[n.first] = dist[cur] + n.second;
                pq.push({dist[n.first], n.first});
            }
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> tcases;
    for (int cc = 1; cc <= tcases; cc++){
        memset(dist, 0x3f, sizeof dist);

        for (int i = 0; i < MAXN; i++)
            adjList[i].clear();

        while(!pq.empty()) pq.pop();

        cin >> N >> M >> S >> T;

        for (int i = 0, a, b, w; i < M; i++){
            cin >> a >> b >> w;
            adjList[a].push_back({b, w});
            adjList[b].push_back({a, w});
        }

        dijkstra(S);

        if (dist[T] != INF)
            printf("Case #%d: %d\n", cc, dist[T]);
        else
            printf("Case #%d: unreachable\n", cc);
    }
}
