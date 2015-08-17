
#include <bits/stdc++.h>

using namespace std;

int T, N, M;
bool matrix[5001][5001], visited[5001];

vector<pair<int, int>> edges;

void bfs(int current){
    if (visited[current]) return;
    visited[current] = true;

    for (int i = 0; i < N; i++){
        if (matrix[current][i]) bfs(i);
    }
}

int main(){

    scanf("%d", &T);

    while(T--){
        memset(matrix, 0, sizeof matrix);
        memset(visited, 0, sizeof visited);
        edges.clear();

        cin >> N >> M;

        for (int i = 0, a, b; i < M; i++){
            cin >> a >> b;
            edges.push_back({a - 1, b - 1});
        }

        for (int i = 0, x; i < N - 1; i++){
            cin >> x;
            int src = edges[x - 1].first, tar = edges[x - 1].second;

            matrix[src][tar] = true, matrix[tar][src] = true;
        }

        bfs(0);

        bool valid = true;
        for (int i = 0; i < N; i++)
            if (!visited[i])
                valid = false;

        if (valid)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
