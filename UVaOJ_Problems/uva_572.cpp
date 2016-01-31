
#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

int N, X, Y;
bool grid[101][101], visited[101][101];

bool dfs(int x, int y){
    if (x < 0 || x >= X || y < 0 || y >= Y) return false;
    if (visited[x][y]) return false;
    if (!grid[x][y]) return false;

    visited[x][y] = true;

    for (int i = 0; i < 8; i++)
        dfs(x + dx[i], y + dy[i]);

    return true;
}

int main(){

    while(true){
        memset(visited, 0, sizeof visited);
        memset(grid, 0, sizeof grid);

        cin >> X >> Y;
        if (X == 0 && Y == 0) break;

        for (int i = 0; i < X; i++){
            string line;
            cin >> line;

            for (int j = 0; j < Y; j++){
                grid[i][j] = (line[j] == '@');
            }
        }

        int cnt = 0;
        for (int i = 0; i < X; i++){
            for (int j = 0; j < Y; j++){
                if (dfs(i, j)) cnt++;
            }
        }

        printf("%d\n", cnt);
    }
}
