
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define MAXN 51

using namespace std;

struct state{
    int cr, cc, st;
    state(int a, int b, int c){
        cr = a, cc = b, st = c;
    }
};

int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};

int R, C, floodtime[MAXN][MAXN];
bool visited[MAXN][MAXN];
char grid[MAXN][MAXN];
vector<pair<int, int>> flood;
queue<state> q;

void sim(){
    for (pair<int, int> i : flood) {
        q.push(state(i.first, i.second, 0));
        floodtime[i.first][i.second] = 0;
    }

    memset(floodtime, 0x3f, sizeof floodtime);
    while(!q.empty()){
        state cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++){
            int nr = cur.cr + dr[i], nc = cur.cc + dc[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (grid[nr][nc] == 'X') continue;
            if (grid[nr][nc] == 'D') continue;

            if (cur.st + 1 < floodtime[nr][nc]){
                floodtime[nr][nc] = cur.st + 1;
                q.push(state(nr, nc, cur.st + 1));
            }
        }
    }
}

int main(){
    cin >> R >> C;
    for (int i = 0; i < R; i++){
        string line;
        cin >> line;
        for (int j = 0; j < C; j++){
            grid[i][j] = line[j];

            if (line[j] == '*') flood.push_back({i, j});
        }
    }
    sim();

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            if (grid[i][j] == 'S'){
                q.push(state(i, j, 0));
            }
        }
    }

    while(!q.empty()){
        state cur = q.front(); q.pop();

        if (grid[cur.cr][cur.cc] == 'D'){
            cout << cur.st << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++){
            int nr = cur.cr + dr[i], nc = cur.cc + dc[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (grid[nr][nc] == 'X') continue;

            bool flag = false;
            for (pair<int, int> p : flood){
                int d = floodtime[nr][nc];
                if (d <= cur.st + 1) flag = true;
            }

            if (flag && grid[nr][nc] != 'D') continue;

            if (!visited[nr][nc]){
                visited[nr][nc] = true;
                q.push(state(nr, nc, cur.st + 1));
            }
        }
    }

    cout << "KAKTUS" << endl;
}

