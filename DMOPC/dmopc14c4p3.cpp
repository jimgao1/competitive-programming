
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define MAXN 1001
#define state pair<int, pair<int, int>>

using namespace std;

int dx[] = {0, 1, -1}, dy[] = {1, 0, 0};

int L, D, tx, ty, dist[MAXN][MAXN], grid[MAXN][MAXN];
priority_queue<state, vector<state>, greater<state>> q;

int main(){
    scanf("%d%d", &L, &D);
    for (int i = 0; i < D; i++){
        for (int j = 0; j < L; j++){
            scanf("%d", &grid[j][i]);
        }
    }
    scanf("%d%d", &tx, &ty);

    memset(dist, 0x3f, sizeof dist);
    q.push({grid[0][0], {0, 0}});

    while(!q.empty()){
        int x = q.top().second.first, y = q.top().second.second;
        int st = q.top().first;
        q.pop();

        if (dist[x][y] < st) continue;
        dist[x][y] = st;

        for (int i = 0; i < 3; i++){
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= L || ny < 0 || ny >= D) continue;
            if (dist[nx][ny] > dist[x][y] + grid[nx][ny]){
                dist[nx][ny] = dist[x][y] + grid[nx][ny];
                q.push({dist[nx][ny], {nx, ny}});
            }
        }
    }

    printf("%d\n", dist[tx][ty]);
}
