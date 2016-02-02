
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int N = 50;
bool visited[51];

int matrix[51][51], dist[51];
queue<pair<int, int>> q;

inline void fadd(int a, int b) { matrix[a][b] = true, matrix[b][a] = true; }

void dfs(int cur, int steps){
    dist[cur] = min(dist[cur], steps);

    if (visited[cur]) return;
    visited[cur] = true;

    for (int i = 0; i < N; i++)
        if (matrix[cur][i] && !visited[i])
            dfs(i, steps + 1);

    visited[cur] = false;
}

int main(){
    fadd(1,6);
    fadd(2,6);
    fadd(3,4);
    fadd(3,5);
    fadd(3,6);
    fadd(3,15);
    fadd(4,5);
    fadd(4,6);
    fadd(5,6);
    fadd(6,7);
    fadd(7,8);
    fadd(8,9);
    fadd(9,10);
    fadd(9,12);
    fadd(10,11);
    fadd(11,12);
    fadd(12,13);
    fadd(13,14);
    fadd(13,15);
    fadd(16,17);
    fadd(16,18);
    fadd(17,18);

    while(true){
        char c;
        int x, y;

        cin >> c;

        if (c == 'i'){
            cin >> x >> y;
            matrix[x][y] = true;
            matrix[y][x] = true;
        } else if (c == 'd'){
            cin >> x >> y;
            matrix[y][x] = false;
            matrix[x][y] = false;
        } else if (c == 'n'){
            cin >> x;
            int cnt = 0;

            for (int i = 0; i < N; i++)
                if (matrix[x][i]) cnt++;

            cout << cnt << endl;
        } else if (c == 'f'){
            cin >> x;
            int cnt = 0;

            memset(visited, 0, sizeof visited);

            for (int i = 0; i < N; i++){
                if (matrix[x][i]){
                    for (int j = 0; j < N; j++){
                        if (matrix[i][j])
                            visited[j] = true;
                    }
                }
            }

            for (int i = 0; i < N; i++)
                if (i != x && visited[i] && !matrix[x][i])
                    cnt++;

            cout << cnt << endl;
        } else if (c == 's'){
            cin >> x >> y;

            memset(visited, 0, sizeof visited);
            memset(dist, 0x3f, sizeof dist);

            dfs(x, 0);
            if (dist[y] == INF)
                cout << "Not connected" << endl;
            else
                cout << dist[y] << endl;

        } else if (c == 'q'){
            break;
        }
    }
}
