
#include <bits/stdc++.h>

#define MAXN 101
#define INF 0x3f3f3f3f

using namespace std;

int N, M, val[MAXN], dist[MAXN], sum[MAXN];
vector<pair<int, int>> adjList[MAXN];
queue<int> q;

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) cin >> val[i];
    cin >> M;
    for (int i = 0, a, b, w; i < M; i++){
        cin >> a >> b >> w;
        adjList[a - 1].push_back({b - 1, w});
        adjList[b - 1].push_back({a - 1, w});
    }

    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    sum[0] = val[0];
    q.push(0);
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for (pair<int, int> i : adjList[cur]){
            int alt = dist[cur] + i.second;
            if (alt <= dist[i.first]){
                if (alt == dist[i.first])
                    sum[i.first] = max(sum[i.first], sum[cur] + val[i.first]);
                else
                    sum[i.first] = sum[cur] + val[i.first];

                dist[i.first] = alt;

                q.push(i.first);
            }
        }
    }

    if (dist[N - 1] == INF){
        cout << "impossible" << endl;
    } else {
        cout << dist[N - 1] << " " << sum[N - 1] << endl;
    }
}

