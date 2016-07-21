
#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

int N, M, c = 0, h = 0;
bool used[MAXN][MAXN];
vector<int> adjList[MAXN];
vector<pair<int, int>> e;

int main(){
	cin >> N >> M;
	for (int i = 0, a, b; i < M; i++){
		cin >> a >> b;
		a--, b--;
		adjList[a].push_back(b);
		adjList[b].push_back(a);

		e.push_back({a, b});
	}

	for (int i = 0; i < N; i++){
		if (adjList[i].size() != 1 &&
			adjList[i].size() != 4){
			cout << "Impossible" << endl;
			return 0;
		}
	}

	for (int i = 0; i < N; i++){
		if (adjList[i].size() == 1){
			h++;
		} else {
			c++;
		}
	}

	int total = 0;

	for (pair<int, int> pii : e){
		if (adjList[pii.first].size() == 1 || adjList[pii.second].size() == 1){
			total += 413;
		} else if (used[pii.first][pii.second] || used[pii.second][pii.first]){
			total += 269;
		} else {
			total += 346;
		}

		used[pii.first][pii.second] = used[pii.second][pii.first] = true;
	}

	cout << total << endl;
	if (c == 1){
		cout << "C";
	} else {
		cout << "C" << c;
	}
	if (h == 1){
		cout << "H";
	} else {
		cout << "H" << h << endl;
	}

}
