
#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>

#define MAXN 101

using namespace std;

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

int N, M;
vector<pair<int, int>> adjList[MAXN][MAXN];
bool visited[MAXN][MAXN], lights[MAXN][MAXN];

void dfs(int x, int y){
    if (visited[x][y]) return;
    visited[x][y] = true;

    for (pair<int, int> p : adjList[x][y]){
        if (lights[p.first][p.second]) continue;
        lights[p.first][p.second] = true;

        for (int i = 0; i < 4; i++){
            int nx = p.first + dx[i], ny = p.second + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visited[nx][ny]){
                dfs(p.first, p.second);
                break;
            }
        }
    }

    for (int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (lights[nx][ny] && !visited[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main(){
    freopen("lightson.in", "r", stdin);
    freopen("lightson.out", "w", stdout);

    scanf("%d%d", &N, &M);

    for (int i = 0, a, b, c, d; i < M; i++){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        adjList[a - 1][b - 1].push_back({c - 1, d - 1});
    }

    lights[0][0] = true;
    dfs(0, 0);

    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (lights[i][j]) ans++;

   printf("%d\n", ans);
}
