
#include <bits/stdc++.h>

using namespace std;

int nodeCount = 7;
bool matrix[10][10];

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

		sort(inDegree.begin(), inDegree.end());



		if (inDegree.empty()) {
			vector<int> e;
			return e;
		}

		for (int i = 0; i <= 0; i++){
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
    memset(matrix, false, sizeof matrix);

    matrix[0][6] = true;
    matrix[0][3] = true;
    matrix[1][0] = true;
    matrix[2][3] = true;
    matrix[2][4] = true;

    while(true){
        int a, b;
        cin >> a >> b;

        if (a == 0 && b == 0) break;
        matrix[a - 1][b - 1] = true;
    }

    vector<int> tasks = topological_sort();

    if (tasks.size() == 0){
        cout << "Cannot complete these tasks. Going to bed." << endl;
        return 0;
    }

    for (int n : tasks)
        cout << (n + 1) << " ";
    cout << endl;
}
