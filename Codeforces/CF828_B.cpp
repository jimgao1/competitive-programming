#include <bits/stdc++.h>
#define MAXN 101

using namespace std;

int N, M;
bool grid[MAXN][MAXN];

int main(){
	cin >> N >> M;

	pair<int, int> a = make_pair(1000, 1000), b = make_pair(-1000, -1000);
	int cnt = 0;

	for (int i = 0; i < N; i++){
		string line;
		cin >> line;
		for (int j = 0; j < M; j++){
			grid[i][j] = (line[j] == 'B');

			if (grid[i][j]){
				a.first = min(a.first, i);
				a.second = min(a.second, j);
				b.first = max(b.first, i);
				b.second = max(b.second, j);

				cnt++;
			}
		}
	}

	if (cnt == 0){
		cout << 1 << endl;
		return 0;
	}
	
	int len = max(b.first - a.first, b.second - a.second) + 1;
	if (len > N || len > M){
		cout << -1 << endl;
		return 0;
	}

	cout << len * len - cnt << endl;
}
