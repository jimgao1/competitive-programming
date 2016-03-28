
#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int N, M, matrix[MAXN][MAXN];
bool visited[MAXN];

vector<int> topological_sort(){
    vector<int> result;
    for (int i = 0; i < N; i++) visited[i] = false;

    while (true){
        bool allVisited = true;
        for (int i = 0; i < N; i++) allVisited = allVisited & visited[i];

        if (allVisited) return result;

        vector<int> inDegree;

        for (int i = 0; i < N; i++){
            if (!visited[i]){
                int indeg = 0;

                for (int j = 0; j < N; j++){
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

            for (int j = 0; j < N; j++){
                matrix[currentNode][j] = -1;
                matrix[j][currentNode] = -1;
            }

            result.push_back(currentNode);
        }
    }
}

int main(){
    while(true){
        cin >> N >> M;
        if (N == 0 && M == 0) break;

        memset(matrix, 0, sizeof matrix);
        memset(visited, 0, sizeof visited);

        for (int i = 0, x, y; i < M; i++){
            cin >> x >> y;

            matrix[x - 1][y - 1] = true;
        }

        vector<int> order = topological_sort();

        for (int i : order)
            printf("%d ", i + 1);
        printf("\n");
    }
}
