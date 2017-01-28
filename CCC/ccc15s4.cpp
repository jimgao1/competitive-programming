
#include <bits/stdc++.h>

#define MAXN 2100
#define INF 0x3f3f3f3f
#define pii pair<int, int>

using namespace std;

struct edge{
    int tar, time, hull;
    edge(int a, int b, int c){
        tar = a, time = b, hull = c;
    }
};

int K, N, M, A, B, dist[MAXN][201];
bool in[MAXN];
vector<edge> adjList[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main(){
    cin >> K >> N >> M;
    for (int i = 0, a, b, t, h; i < M; i++){
        cin >> a >> b >> t >> h;
        adjList[a].push_back(edge(b, t, h));
        adjList[b].push_back(edge(a, t, h));
    }
    cin >> A >> B;

    memset(dist, 0x3f, sizeof dist);

    pq.push({0, A});
    dist[A][0] = 0;
    in[A] = true;

    while(!pq.empty()){
        int cur = pq.top().second;
        in[cur] = false;
        pq.pop();

        for (edge e : adjList[cur]){
            for (int i = 0; i + e.hull < K; i++){
                int alt = dist[cur][i] + e.time;

                if (alt < dist[e.tar][i + e.hull]){
                    dist[e.tar][i + e.hull] = alt;

                    if (!in[e.tar]){
                        in[e.tar] = true;
                        pq.push({alt, e.tar});
                    }
                }
            }
        }
    }

    int ans = INF;
    for (int i = 0; i < K; i++){
        ans = min(ans, dist[B][i]);
    }

    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

