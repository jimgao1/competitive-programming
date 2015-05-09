#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double prob[1100000] = { 0 };
vector<int> adjList[1100000];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int nodes, edges;
	cin >> nodes >> edges;

	prob[0] = 1;

	for (int i = 0; i < edges; i++){
		int a, b;
		cin >> a >> b;

		adjList[a - 1].push_back(b - 1);
	}

	for (int i = 0; i < nodes; i++){
		if (adjList[i].size() != 0){
			double p = prob[i] / adjList[i].size();

			for (int j = 0; j < adjList[i].size(); j++)
				prob[adjList[i][j]] += p;
		}
	}

	for (int i = 0; i < nodes; i++){
		if (adjList[i].size() == 0)
			cout << setprecision(9) << prob[i] << "\n";
	}

	system("pause");
	return 0;
}
