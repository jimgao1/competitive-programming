#include <bits/stdc++.h>

#define MAXN 500001

using namespace std;

int N, cnt = 0, edge[MAXN], degree[MAXN];
bool visited[MAXN];

void dfs(int cur, bool ma){
	if (visited[cur]) return;
	visited[cur] = true;

	if (ma) cnt++;
	degree[edge[cur]] -= 1;

	if (degree[edge[cur]] == 0 || ma)
		dfs(edge[cur], !ma);
}

int main(){
	scanf("%d", &N);
	for (int i = 0, x; i < N; i++){
		scanf("%d", &x);
		edge[i] = x - 1;
		degree[edge[i]] += 1;
	}

	for (int i = 0; i < N; i++)
		if (degree[i] == 0)
			dfs(i, true);

	for (int i = 0; i < N; i++)
		dfs(i, false);


	printf("%d\n", cnt);
}
