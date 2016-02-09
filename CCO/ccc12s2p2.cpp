
#include <bits/stdc++.h>

#define MAXN 20001
#define INF 0x3f3f3f3f
#define pii pair<int, int>

using namespace std;

int N, M, dist1[MAXN], dist2[MAXN];
vector<pii> list1[MAXN], list2[MAXN];
vector<pair<pii, int>> edges;

priority_queue<pii, vector<pii>, greater<pii>> q;

void dijkstra(int* dist, vector<pii>* adjList, int src){
    memset(dist, 0x3f, sizeof dist);
    while(!q.empty()) q.pop();

    dist[src] = 0;
    q.push({0, src});
    while(!q.empty()){
        int cur = q.top().second, st = q.top().first;
        q.pop();

        for (auto i : adjList[cur]){
            if (dist[i.first] > dist[cur] + i.second){
                dist[i.first] = dist[cur] + i.second;
                q.push({dist[i.first], i.first});
            }
        }
    }
}

int main(){
    scanf("%d%d", &N, &M);
    for (int i = 0, a, b, c; i < M; i++){
        scanf("%d%d%d", &a, &b, &c);
        list1[a].push_back({b, c});
        list2[b].push_back({a, c});

        edges.push_back({{a, b}, c});
    }

    memset(dist1, 0x3f, sizeof dist1);
    memset(dist2, 0x3f, sizeof dist2);

    dijkstra(dist1, list1, 1);
    dijkstra(dist2, list2, N);

    int shortest = dist1[N], ans = INF;
    for (auto e : edges){
        int nd = dist1[e.first.first] + dist2[e.first.second] + e.second;
        if (nd > shortest && nd < ans){
            ans = nd;
        }
    }

    if (ans == INF)
        printf("-1\n");
    else
        printf("%d\n", ans);
}
