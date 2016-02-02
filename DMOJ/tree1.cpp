
#include <bits/stdc++.h>

using namespace std;

inline bool getBit(int n, int bit) { return (n & (1 << bit)); }
inline int setBit(int n, int bit) { return (n | (1 << bit)); }

int visited = 0, edges = 0;
bool matrix[5][5];

void bfs(int node){
    if (getBit(visited, node)) return;
    visited = setBit(visited, node);

    for (int i = 0; i < 4; i++) if (!getBit(visited, i) && matrix[node][i]) bfs(i);
}

int main(){
    for (int i = 0; i < 4; i++){
        for (int j = 0, x; j < 4; j++){
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 1) edges++;
        }
    }

    if (edges != 6) { printf("No\n"); return 0; }

    bfs(0);

    if (visited == 15) { printf("Yes\n"); return 0; }
    printf("No\n");
}
