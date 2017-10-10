
//Credits: https://github.com/alxli/Algorithm-Anthology/blob/master/Section-2-Graph-Theory/2.5.1%20Max%20Flow%20(Ford-Fulkerson).cpp

#include <bits/stdc++.h>

#define MAXN 101
#define INF 0x3f3f3f3f

using namespace std;

/*
	N: Number of nodes
	M: Number of edges
	S: Source
	T: Sink
*/

int N, M, S, T, cap[MAXN][MAXN];
bool visited[MAXN];

int dfs(int cur, int flow){
	if (cur == T) return flow;
	visited[cur] = true;

	for (int i = 0; i < N; i++){
		if (!visited[i] && cap[cur][i] > 0){
			int f = dfs(i, min(flow, cap[cur][i]));
			if (f > 0){
				cap[cur][i] -= f;
				cap[i][cur] += f;

				return f;
			}
		}
	}
	return 0;
}

int ford_fulkerson(){
	int max_flow = 0;
	while(true){
		memset(visited, 0, sizeof visited);

		int new_flow = dfs(S, INF);
		if (new_flow == 0) break;
		max_flow += new_flow;
	}
	
	return max_flow;
}

int main(){
	N = 6;
	S = 0;
	T = 5;

	cap[0][1] = 3;
	cap[0][2] = 3;
	cap[1][2] = 2;
	cap[1][3] = 3;
	cap[2][4] = 2;
	cap[3][4] = 1;
	cap[3][5] = 2;
	cap[4][5] = 3;

	assert(ford_fulkerson() == 5);	
}
