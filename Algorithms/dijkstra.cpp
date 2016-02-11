
#include <bits/stdc++.h>

#define MAXN 2000

using namespace std;

int N, M, dist[MAXN];
vector<pair<int, int>> adjList[MAXN];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dijkstra;

void dijkstra(int src){
	memset(dist, 0x3f, sizeof dist);
	dist[src] = 0;

	dijkstra.push({0, src});
	while(!dikjstra.empty()){
		int cur = dijkstra.top().second, st = dijkstra.top().first;
		dijkstra.pop();

		for (pair<int, int> i : adjList[cur]){
			if (dist[i.first] > dist[cur] + i.second){
				dist[i.first] = dist[cur] + i.second;
				dijkstra.push({dist[i.first], i.first});
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
}
