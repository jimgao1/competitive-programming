
#include <bits/stdc++.h>

#define MAXN 10004
#define LOGMAXN 15
#define ll long long
#define pii pair<int, int>

using namespace std;

inline bool getBit(int n, int idx) { return n & (1 << idx); }

int T, N;
int dp[MAXN][LOGMAXN], depth[MAXN];
ll dist[MAXN];

vector<pii> adjList[MAXN];

void dfs(int cur, int dep, int prev){
	dp[cur][0] = prev;
	depth[cur] = dep;
	for (pii i : adjList[cur]){
		if (i.first != prev){
			dist[i.first] = dist[cur] + i.second;
			dfs(i.first, dep + 1, cur);
		}
	}
}

void build(){
	for (int i = 1; i < LOGMAXN; i++){
		for (int j = 0; j < N; j++){
			if (dp[j][i - 1] != -1){
				dp[j][i] = dp[dp[j][i - 1]][i - 1];
			}
		}
	}
}

int lca(int na, int nb){
	if (depth[na] < depth[nb]) swap(na, nb);

	for (int i = LOGMAXN - 1; i >= 0; i--){
		if (dp[na][i] != -1 && depth[dp[na][i]] >= depth[nb]){
			na = dp[na][i];
		}
	}

	if (na == nb) return na;

	for (int i = LOGMAXN - 1; i >= 0; i--){
		if (dp[na][i] != -1 && dp[nb][i] != -1 && dp[na][i] != dp[nb][i]){
			na = dp[na][i], nb = dp[nb][i];
		}
	}

	return dp[na][0];
}

int fetch(int node, int dist){
	for (int i = 0; (1 << i) <= dist; i++){
		if (getBit(dist, i)) node = dp[node][i];
	}
	return node;
}

void solve(){
	cin >> N;
	for (int i = 0, a, b, w; i < N - 1; i++){
		cin >> a >> b >> w;
		a--, b--;
		adjList[a].push_back(make_pair(b, w));
		adjList[b].push_back(make_pair(a, w));
	}

	dfs(0, 0, -1);
	build();

	while(true){
		string cmd;
		int a, b, c;

		cin >> cmd;
		if (cmd == "DIST"){
			cin >> a >> b;
			a--, b--;
			int l = lca(a, b);
			
			cout << dist[a] + dist[b] - 2 * dist[l] << endl;
		} else if (cmd == "KTH"){
			cin >> a >> b >> c;
			a--, b--, c--;
			
			int l = lca(a, b);
			int llen = depth[a] - depth[l] + 1, rlen = depth[b] - depth[l];

			if (c < llen){
				cout << fetch(a, c) + 1 << endl;
			} else {
				cout << fetch(b, llen + rlen - c - 1) + 1 << endl;
			}
		} else {
			break;
		}
	}

	cout << endl;
}

int main(){
	cin >> T;
	while(T--){
		memset(dp, 0, sizeof dp);
		memset(depth, 0, sizeof depth);
		memset(dist, 0, sizeof dist);

		for (int i = 0; i < MAXN; i++){
			adjList[i].clear();
		}

		solve();
	}
}

