
#include <iostream>
#include <vector>

using namespace std;

int matrix[100][100];
int nodeCount;

vector<int> topological_sort(){
	vector<int> result;
	bool *visited = new bool[nodeCount];

	for (int i = 0; i < nodeCount; i++) visited[i] = false;

	while (true){
		bool allVisited = true;
		for (int i = 0; i < nodeCount; i++) allVisited = allVisited & visited[i];

		if (allVisited) return result;

		vector<int> inDegree;

		for (int i = 0; i < nodeCount; i++){
			if (!visited[i]){
				int indeg = 0;

				for (int j = 0; j < nodeCount; j++){
					if (!visited[j] && matrix[j][i]) indeg += 1;
				}

				if (indeg == 0) inDegree.push_back(i);
			}
		}

		if (inDegree.empty()) {
			vector<int> e;
			return e;
		}

		for (int i = 0; i < inDegree.size(); i++){
			int currentNode = inDegree[i];

			visited[currentNode] = true;

			for (int j = 0; j < nodeCount; j++){
				matrix[currentNode][j] = -1;
				matrix[j][currentNode] = -1;
			}

            		result.push_back(currentNode);
		}
	}
}

int main(){
	cin >> nodeCount;

	int comp;
	cin >> comp;

	for (int i = 0; i < comp; i++){
		int src, tar;
		cin >> src >> tar;

		matrix[src][tar] = 1;
	}

	vector<int> result = topological_sort();

	for (int n : result)
		cout << n << endl;
}
