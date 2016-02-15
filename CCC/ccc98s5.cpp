
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

int T, N, grid[30][30], dist[30][30];
queue<pair<pair<int, int>, int>> q;

int main(){
    scanf("%d", &T);
    while(T--){
        memset(dist, 0x3f, sizeof dist);

        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &grid[i][j]);

        int ans = INF;

        q.push({{0, 0}, 0});
        while(!q.empty()){
            int x = q.front().first.first, y = q.front().first.second;
            int oxygen = q.front().second;
            q.pop();

            if (dist[x][y] <= oxygen) continue;
            dist[x][y] = oxygen;

            for (int i = 0; i < 4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

                if (abs(grid[x][y] - grid[nx][ny]) > 2) continue;

                if (grid[nx][ny] > grid[0][0] || grid[x][y] > grid[0][0]){
                    q.push({{nx, ny}, oxygen + 1});
                } else {
                    q.push({{nx, ny}, oxygen});
                }
            }
        }

        if (dist[N - 1][N - 1] == INF)
            printf("CANNOT MAKE THE TRIP\n");
        else
            printf("%d\n", dist[N - 1][N - 1]);
    }
}
