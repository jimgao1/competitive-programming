
#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int dr[] = {0, 0, 1, -1}, dc[] = {1, -1, 0, 0};

int R, C, grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
queue<pair<int, int>> q;

bool test(int a, int b, int c){
    memset(visited, 0, sizeof visited);
    while(!q.empty()) q.pop();

    for (int i = 0; i < C; i++){
        q.push({0, i});
    }

    while(!q.empty()){
        int cr = q.front().first, cc = q.front().second;
        q.pop();

        if (visited[cr][cc]) continue;
        visited[cr][cc] = true;

        if (cr == R - 1){
            return true;
        }

        for (int i = 0; i < 4; i++){
            int nr = cr + dr[i], nc = cc + dc[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (grid[nr][nc] == a || grid[nr][nc] == b || grid[nr][nc] == c){
                q.push({nr, nc});
            }
        }
    }

    return false;
}

int main(){
    cin >> C >> R;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < 10; i++){
        for (int j = i; j < 10; j++){
            for (int k = j; k < 10; k++){
                if (test(i, j, k)){
                    printf("%d %d %d\n", i, j, k);
                    return 0;
                }
            }
        }
    }

    printf("-1 -1 -1\n");
}
