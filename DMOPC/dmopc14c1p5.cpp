
#include <bits/stdc++.h>

#define endl "\n"
#define INF 0x40404040

using namespace std;

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

int R, C, T, tr, tc, cr, cc, dist[1001][1001];
bool grid[1001][1001], teleport[1001][1001];

vector<pair<int, int>> tel;
queue<pair<int, int>> q;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C >> cr >> cc >> tr >> tc;
    for (int i = 0; i < R; i++){
        string str;
        cin >> str;

        for (int j = 0; j < C; j++){
            grid[i][j] = (str[j] == 'X');
        }
    }
    cin >> T;
    for (int i = 0, r, c; i < T; i++){
        cin >> r >> c;
        tel.push_back({r, c});
        teleport[r][c] = true;
    }

    memset(dist, 0x40, sizeof dist);

    q.push({cr, cc});
    dist[cr][cc] = 0;

    while(!q.empty()){
        int r = q.front().first, c = q.front().second;
        q.pop();

        if (teleport[r][c]) continue;
        if (r == tr && c == tc) break;

        for (int i = 0; i < 4; i++){
            int nr = r + dx[i], nc = c + dy[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (grid[nr][nc]) continue;
            if (dist[r][c] + 1 > dist[nr][nc]) continue;
            dist[nr][nc] = min(dist[nr][nc], dist[r][c] + 1);

            q.push({nr, nc});
        }
    }

    int minDist = INF;

    for (auto i : tel){
        minDist = min(minDist, dist[i.first][i.second]);
    }

    if (dist[tr][tc] == INF){
        cout << 2 << endl;
        return 0;
    }

    if (dist[tr][tc] - minDist < 0)
        cout << dist[tr][tc] << endl;
    else
        cout << dist[tr][tc] - minDist << endl;

}
