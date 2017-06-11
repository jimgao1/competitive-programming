#include <bits/stdc++.h>

#define MAXN 501

using namespace std;

int N, M, deg[MAXN];
bool visited[MAXN];
set<int> adj[MAXN];

vector<int> toposort(){
	vector<int> order;

	while(true){
		bool flag = true;
		for (int i = 0; i < N; i++) flag &= visited[i];
		if (flag) return order;

		vector<int> todo;
		for (int i = 0; i < N; i++){
			if (!visited[i] && deg[i] == 0)
				todo.push_back(i);
		}

		if (todo.empty()) return todo;

		for (int cur : todo){
			order.push_back(cur);
			visited[cur] = 1;

			for (int i : adj[cur]){
				deg[i] --;
			}

		}
	}
}

int main(){
	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0, x; j < N; j++){
			cin >> x;
			if (x == 1){
				adj[i].insert(j);
				deg[j] ++;
			}
		}
	}

	vector<int> order = toposort();

	if (order.empty()){
		cout << "impossible" << endl;
	} else {
		for (int i : order) cout << i + 1 << endl;
	}
}
