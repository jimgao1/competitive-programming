
#include <bits/stdc++.h>

#define MAXN 1601
#define INF 0x3f3f3f3f
#define state pair<pair<int, int>, int>

using namespace std;

struct edge{
    int tar, weight;
    bool above;
};

int S, N, M, mdist[MAXN], ans = INF;
vector<edge> adjList[MAXN];
priority_queue<state, vector<state>, greater<state>> q;

int main(){
    memset(mdist, 0x3f, sizeof mdist);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> S >> N >> M;
    for (int i = 0, a, b, d, u; i < M; i++){
        cin >> a >> b >> d >> u;
        adjList[a].push_back({b, d, u});
        adjList[b].push_back({a, d, u});
    }

    q.push({{0, 0}, 0});

    while(!q.empty()){
        int cur = q.top().second;
        int dist = q.top().first.second, exp = q.top().first.first;
        q.pop();

        //printf("cur = %d, dist = %d, exp = %d\n", cur, dist, exp);

        if (cur == N - 1 && exp <= S){
            ans = min(ans, dist);
            continue;
        }

        if (exp > S) continue;
        if (mdist[cur] < dist) continue;
        mdist[cur] = min(mdist[cur], dist);

        for (edge e : adjList[cur]){
            int nx = 0;
            if (e.above) nx = e.weight;
            if (exp + nx <= S && dist + e.weight < mdist[e.tar])
                q.push({{exp + nx, dist + e.weight}, e.tar});
        }
    }

    cout << (ans == INF ? -1 : ans) << "\n";
}
