
#include <bits/stdc++.h>

#define MAXN 1001
#define pii pair<double, int>

using namespace std;

struct edge{
    int tar;
    double dist, limit;
    edge(int a, double b, double c){
        tar = a, dist = b, limit = c;
    }
};

int N, M, cnt[MAXN];
double dist[MAXN];
vector<edge> adjList[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dijkstra(int src){
    for (int i = 0; i < MAXN; i++) dist[i] = 1e9, cnt[i] = 1e9;
    dist[src] = 0, cnt[src] = 0;

    pq.push({0, src});
    while(!pq.empty()){
        int cur = pq.top().second, st = pq.top().first;
        pq.pop();

        for (edge e : adjList[cur]){
            double alt = dist[cur] + (double)e.dist / (double)(e.limit);
            if (alt < dist[e.tar] || (alt == dist[e.tar] && cnt[cur] + 1 <= cnt[e.tar])){
                dist[e.tar] = alt;
                cnt[e.tar] = cnt[cur] + 1;

                pq.push({dist[e.tar], e.tar});
            }
        }
    }
}

int main(){
    cin >> N >> M;
    for (int i = 0, a, b, d, s; i < M; i++){
        cin >> a >> b >> d >> s;
        a--, b--;
        adjList[a].push_back(edge(b, d, s));
        adjList[b].push_back(edge(a, d, s));
    }

    dijkstra(0);

    printf("%d\n", cnt[N - 1]);
    printf("%.0f\n", 60.0 * (dist[N - 1] / 0.75 - dist[N - 1]));
}

