

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

#define pii pair<int, int>
#define INF 0x3f3f3f3f

using namespace std;

struct edge{
    int tar, dist, cost;

    edge(int a, int b, int c){
        tar = a, dist = b, cost = c;
    }
};

int K, N, R, dist[101][10001], minDist = INF;
bool visited[101];
vector<edge> g[101];

bool comp(edge a, edge b){
    if (a.dist == b.dist)
        return a.cost < b.cost;
    return a.dist < b.dist;
}

void dfs(int cur, int tdist, int tremain){
    if (tdist > minDist) return;
    if (tremain < 0) return;
    if (cur == N){
        if (tremain >= 0 && tdist < minDist)
            minDist = tdist;
        return;
    }

    if (dist[cur][tremain] < tdist) return;
    dist[cur][tremain] = tdist;

    for (int i = 0; i < g[cur].size(); i++){
        if (!visited[g[cur][i].tar] && tremain - g[cur][i].cost >= 0){
            visited[cur] = true;
            dfs(g[cur][i].tar, tdist + g[cur][i].dist, tremain - g[cur][i].cost);
            visited[cur] = false;
        }
    }
}

int main(){
    scanf("%d%d%d", &K, &N, &R);
    for (int i = 0, s, d, l, t; i < R; i++){
        scanf("%d%d%d%d", &s, &d, &l, &t);
        g[s].push_back(edge(d, l, t));
    }

    for (int i = 0; i <= N; i++) sort(g[i].begin(), g[i].end(), comp);

    memset(dist, 0x3f, sizeof dist);
    dfs(1, 0, K);

    if (minDist == INF) minDist = -1;

    printf("%d\n", minDist);
}
