#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define pii pair<int, int>

using namespace std;

int T, K, N, D, p[5001], dist[5001];
vector<pair<int, int>> adjList[5001];

priority_queue<pii, vector<pii>, greater<pii>       > q;

void dijkstra(int src){
    memset(dist, 0x3f, sizeof dist);
    dist[src] = 0;

    q.push({0, src});
    while(!q.empty()){
        int cur = q.top().second;
        int d = q.top().first;
        q.pop();

        if (dist[cur] < d) continue;

        for (auto i : adjList[cur]){
            int alt = dist[cur] + i.second;

            if (alt < dist[i.first]){
                dist[i.first] = alt;
                q.push({dist[i.first], i.first});
            }
        }
    }
}

int main(){
    scanf("%d%d", &N, &T);

    memset(p, 0x3f, sizeof p);
    for (int i = 0, a, b, c; i < T; i++){
        scanf("%d%d%d", &a, &b, &c);

        adjList[a - 1].push_back({b - 1, c});
        adjList[b - 1].push_back({a - 1, c});
    }

    scanf("%d", &K);
    for (int i = 0, a, b; i < K; i++){
        scanf("%d%d", &a, &b);
        p[a - 1] = b;
    }

    scanf("%d", &D);

    dijkstra(D - 1);
    for (int i = 0; i < N; i++)
        dist[i] += p[i];

    int ans = INF;
    for (int i = 0; i < N; i++){
        if (p[i] != INF)
            ans = min(ans, dist[i]);
    }

    printf("%d\n", ans);
}
