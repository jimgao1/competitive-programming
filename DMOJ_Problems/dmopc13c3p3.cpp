
#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

int N, H, field[1501][1501];
bool visited[1501][1501];
queue<pair<int, int>> q;

int main(){
    scanf("%d%d", &N, &H);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &field[i][j]);

    q.push({0, 0});

    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();

        if (x == N - 1 && y == N - 1) break;

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (abs(field[x][y] - field[nx][ny]) > H) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;

            q.push({nx, ny});
        }
    }

    if (visited[N - 1][N - 1])
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
