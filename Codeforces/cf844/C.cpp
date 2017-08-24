
#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

int N, A[MAXN];
bool visited[MAXN];
map<int, int> mp;
vector<int> tmp, fuck, adjList[MAXN];
vector<vector<int>> results;

void mark(int cur){
	visited[cur] = 1;
	fuck.push_back(cur);
	for (int i : adjList[cur]){
		if (!visited[i])
			mark(i);
	}
}

int main(){
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		tmp.push_back(A[i]);
	}
	sort(tmp.begin(), tmp.end());

	for (int i = 0; i < N; i++) mp[tmp[i]] = i;
	for (int i = 0; i < N; i++) A[i] = mp[A[i]];

	for (int i = 0; i < N; i++){
		adjList[i].push_back(A[i]);
	}

	int ans = 0;
	for (int i = 0; i < N; i++){
		if (!visited[i]){
			ans++;
			fuck.clear();
			mark(i);

			vector<int> ttmp;
			for (int x : fuck) ttmp.push_back(x);
			results.push_back(ttmp);
		}
	}

	printf("%d\n", ans);
	for (vector<int> i : results){
		printf("%d", i.size());
		for (int x : i) printf(" %d", x + 1);
		printf("\n");
	}
}
