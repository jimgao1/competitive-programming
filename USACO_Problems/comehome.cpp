/*
ID: jim.yub1
PROG: comehome
LANG: C++11
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;

int matrix[130][130];
int t_dist[260];

void update_distance(int node, int dist){
	if (t_dist[node] <= dist) return;
	t_dist[node] = dist;

	for (int i = 0; i < 130; i++)
		if (matrix[node][i] != INF)
			update_distance(i, dist + matrix[node][i]);
}

int main(){
	freopen("comehome.in", "r", stdin);
	freopen("comehome.out", "w", stdout);

	for (int i = 0; i < 130; i++)
		for (int j = 0; j < 130; j++)
			matrix[i][j] = INF;

	for (int i = 0; i < 260; i++)
		t_dist[i] = INF;

	int edges;
	cin >> edges;

	for (int i = 0; i < edges; i++){
		char orig, tar;
		int dist;

		cin >> orig >> tar >> dist;

		matrix[orig][tar] = min(matrix[orig][tar], dist);
		matrix[tar][orig] = min(matrix[tar][orig], dist);
	}

	update_distance('Z', 0);

	char minNode;
	int minDist = INF;

	for (char c = 'A'; c < 'Z'; c++)
		if (t_dist[c] < minDist){
			minNode = c;
			minDist = t_dist[c];
		}

	cout << minNode << " " << minDist << endl;

	//system("pause");
	return 0;

}
