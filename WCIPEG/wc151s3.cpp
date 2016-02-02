#include <bits/stdc++.h>

#define INF 1e12
#define ll long long

using namespace std;

int N, M, K, p[210000];
ll dist1[210000], dist2[210000];

vector<pair<int, int>> adjList[210000];
vector<pair<ll, int>> site;

priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> > pq;

void dijkstra(ll* dist, int src){
    while(!pq.empty()) pq.pop();

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        ll cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] < cost) continue;

        for (int i = 0; i < adjList[cur].size(); i++){
            int tar = adjList[cur][i].first;
            int weight = adjList[cur][i].second;

            if (dist[tar] > cost + weight){
                dist[tar] = cost + weight;
                pq.push({dist[tar], tar});
            }
        }
    }

}

int main(){
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 0; i < N; i++) scanf("%d", &p[i]);

    for (int i = 0, a, b, c; i < M; i++){
        scanf("%d%d%d", &a, &b, &c);

        adjList[b - 1].push_back({a - 1, c});
    }

    for (int i = 0; i < N; i++){
        dist1[i] = INF, dist2[i] = INF;
    }

    dijkstra(dist1, 0);
    dijkstra(dist2, 1);

    for (int i = 0; i < N; i++){
        if (dist1[i] == INF && dist2[i] == INF && p[i] != 0){
            printf("-1\n");
            return 0;
        }
    }

    ll ans = 0, t = 0;

    for (int i = 0; i < N; i++){
        if (dist1[i] <= dist2[i]){
            ans += dist1[i] * p[i];
        } else {
            site.push_back({dist1[i] - dist2[i], i});
            t += p[i];

        }
    }

    if (t > K){
        sort(site.begin(), site.end());

        t -= K;
        while(t > 0){

            if (dist1[site[0].second] == INF){
                printf("-1\n");
                return 0;
            }

            if (t <= p[site[0].second]){
                ans += t * dist1[site[0].second];
                p[site[0].second] -= t;
                t = 0;
            } else {
                ans += p[site[0].second] * dist1[site[0].second];
                t -= p[site[0].second];
                site.erase(site.begin());
            }
        }
    }



    for (int i = 0; i < site.size(); i++){
        ans += p[site[i].second] * dist2[site[i].second];
    }

    printf("%lld\n", ans);
}
