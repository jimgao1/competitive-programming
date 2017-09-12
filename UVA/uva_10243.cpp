
#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

int N, dp[MAXN][MAXN][2];
vector<int> adjList[MAXN];

int dfs(int cur, int pre, int place){
	if (dp[cur][pre][place] != -1) return dp[cur][pre][place];

	int ans = place ? 1 : 0;
	for (int i : adjList[cur]){
		if (i != pre){
			if (place){
				ans += min(dfs(i, cur, 1), dfs(i, cur, 0));
			} else {
				ans += dfs(i, cur, 1);
			}
		}
	}
	return dp[cur][pre][place] = ans;
}

int solve(){
	for (int i = 0; i < MAXN; i++) adjList[i].clear();
	memset(dp, -1, sizeof dp);
	for (int i = 0, x; i < N; i++){
		cin >> x;
		for (int j = 0, y; j < x; j++){
			cin >> y;
			adjList[i].push_back(y - 1);
		}
	}

	// Trivial case, N = 1
	if (N == 1) return 1;
	return min(dfs(0, 0, 0), dfs(0, 0, 1));
}

int main(){
	while(true){
		cin >> N;
		if (N == 0) break;
		cout << solve() << endl;
	}
}
