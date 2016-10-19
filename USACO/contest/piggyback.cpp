
#include <bits/stdc++.h>

#define MAXN 40001
#define INF 0x3f3f3f3f
#define pii pair<int, int>

using namespace std;

int B, E, P, N, M, ddist[3][MAXN];
vector<int> adjList[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dijkstra(int* dist, int src){
    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        int cur = pq.top().second, st = pq.top().first;
        pq.pop();

        for (int n : adjList[cur]){
            int alt = st + 1;
            if (dist[n] > alt){
                dist[n] = alt;
                pq.push({alt, n});
            }
        }
    }
}

int main(){
    freopen("piggyback.in", "r", stdin);
    freopen("piggyback.out", "w", stdout);

    cin >> B >> E >> P >> N >> M;
    for (int i = 0, a, b; i < M; i++){
        cin >> a >> b;
        adjList[a - 1].push_back(b - 1);
        adjList[b - 1].push_back(a - 1);
    }

    memset(ddist, 0x3f, sizeof ddist);
    dijkstra(ddist[0], N - 1);
    dijkstra(ddist[1], 0);
    dijkstra(ddist[2], 1);

    int ans = INF;
    for (int i = 0; i < N; i++){
        int total = ddist[1][i] * B + ddist[2][i] * E + ddist[0][i] * P;
        ans = min(ans, total);
    }

    cout << ans << endl;
}

