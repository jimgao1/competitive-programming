
#include <bits/stdc++.h>

#define MAXN 100001

using namespace std;

int N, M, dist1[MAXN], dist2[MAXN];
vector<pair<int, int>> adjList[MAXN];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

void dijkstra(int* dist, int src){
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
    for (int i = 0, src, tar, weight; i < M; i++){
        scanf("%d%d%d", &src, &tar, &weight);
        adjList[src].push_back({tar, weight});
        adjList[tar].push_back({src, weight});
    }

    memset(dist1, 0x3f, sizeof dist1);
    memset(dist2, 0x3f, sizeof dist2);

    dijkstra(dist1, 0);
    dijkstra(dist2, N - 1);

    int ans = 0;

    for (int i = 1; i < N - 1; i++){
        ans = max(ans, dist1[i] + dist2[i]);
    }

    printf("%d\n", ans);
}
