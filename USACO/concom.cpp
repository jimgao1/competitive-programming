/*

ID: jim.yub1
LANG: C++11
TASK: concom

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

int ownership[100][100] = { 0 };
int c[100];
bool visited[100] = { false };

int compCount = 0;

void dfs(int current){
	visited[current] = true;

	for (int i = 0; i < 100; i++) c[i] += ownership[current][i];
	for (int i = 0; i < 100; i++) if (c[i] > 50 && !visited[i]) dfs(i);
}

int main(){
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);

	int connections;
	cin >> connections;

	for (int i = 0; i < connections; i++){
		int cA, cB, s;
		cin >> cA >> cB >> s;

		compCount = max(compCount, cA);
		compCount = max(compCount, cB);

		ownership[cA - 1][cB - 1] = s;
	}

	for (int i = 0; i < 100; i++){
		memset(visited, false, sizeof(visited));
		memset(c, 0, sizeof(c));

		dfs(i);

		for (int j = 0; j < 100; j++)
			if (j != i && visited[j])
				cout << i + 1 << " " << j + 1 << endl;
	}

	//system("pause");
	return 0;
}
