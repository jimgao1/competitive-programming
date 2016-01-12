#include <bits/stdc++.h>

#define MAXN 10001
#define INF 0x3f3f3f3f

using namespace std;

int N, dist[MAXN];
bool visited[MAXN];

vector<pair<int, int>> adjList[MAXN];

void dijsktra(int src){

	//Initialization of distance array
	memset(dist, 0x3f, sizeof dist);
	dist[src] = 0;

	while(true){
		int curNode = -1, curDist = INF;

		//Find the node with min current distance
		for (int i = 0; i < N; i++){
			if (visited[i] && dist[i] < minDist){
				minDist = dist[i];
				curNode = i;
			}
		}

		//If all nodes are visited, then break the loop
		if (curNode == -1) break;

		//Set the current node to visited
		visited[curNode] = true;

		//Access all the adjacent nodes
		
		for (auto i : adjList[curNode]){
			dist[i.first] = min(dist[i.first], dist[curNode] + i.second);
		}
	}
}

int main(){

}
