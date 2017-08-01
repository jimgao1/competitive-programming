
#include <bits/stdc++.h>

using namespace std;

int N, M;
map<int, vector<int>> mp;

void solve(){
	scanf("%d", &M);
	for (int i = 0, x; i < N; i++){
		scanf("%d", &x);
		mp[x].push_back(i);
	}
	for (int i = 0, k, v; i < M; i++){
		scanf("%d%d", &k, &v);
		printf("%d\n", mp[v].size() >= k ? mp[v][k - 1] + 1 : 0);
	}
}

int main(){
	while(scanf("%d", &N) != EOF){
		mp.clear();
		solve();
	}
}
