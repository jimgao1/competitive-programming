
#include <bits/stdc++.h>

#define MAXN 1001
#define INF 0x3f3f3f3f
#define pii pair<int, int>

using namespace std;

int N, M, dist[MAXN];
vector<pii> adjList[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dijkstra(int src){
    memset(dist, 0x3f, sizeof dist);
    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        int cur = pq.top().second, st = pq.top().first;
        pq.pop();

        for (pii c : adjList[cur]){
            int alt = st + c.second;
            if (alt < dist[c.first]){
                dist[c.first] = alt;
                pq.push({dist[c.first], c.first});
            }
        }
    }
}

int main(){
    cin >> N >> M;
    for (int i = 0, a, b, w; i < M; i++){
        cin >> a >> b >> w;
        adjList[a].push_back({b, w});
        adjList[b].push_back({a, w});
    }

    dijkstra(1);
    for (int i = 1; i <= N; i++)
        cout << (dist[i] == INF ? -1 : dist[i]) << endl;
}
