
#include <bits/stdc++.h>

#define MAXN 100000
#define INF 0x3f3f3f3f
#define pii pair<int, int>

using namespace std;

int N, M, A, B, C, dist1[MAXN], dist2[MAXN];
vector<pii> adjList[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dijkstra(int src, int* dist){
	dist[src] = 0;

	pq.push({0, src});
	while(!pq.empty()){
		int cur = pq.top().second, st = pq.top().first;
		pq.pop();

		for (pii i : adjList[cur]){
			if (dist[i.first] > dist[cur] + i.second){
				dist[i.first] = dist[cur] + i.second;
				pq.push({dist[i.first], i.first});
			}
		}
	}
}

int cost(int d){
    int ans = min(d, 10) * 2 + max(0, d - 10) * 1;
    return ans + 3;
}

int main(){
    cin >> N >> M >> A >> B >> C;
    for (int i = 0, a, b, w; i < M; i++){
        cin >> a >> b >> w;
        adjList[a].push_back({b, w});
        adjList[b].push_back({a, w});
    }
    memset(dist1, 0x3f, sizeof dist1); memset(dist2, 0x3f, sizeof dist2);
    dijkstra(A, dist1);
    dijkstra(B, dist2);

    if (dist1[B] == INF){
        cout << "Nooooooooo!!!" << endl;
    } else if (dist2[C] == INF){
        cout << cost(dist1[B]) << endl;
        cout << "Yippee!!!" << endl;
    } else {
        cout << cost(dist1[B] + dist2[C]) << endl;
    }
}

