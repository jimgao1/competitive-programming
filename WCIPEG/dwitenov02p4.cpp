
#include <bits/stdc++.h>

#define MAXN 300

using namespace std;

int N, grid[MAXN][MAXN], dist[MAXN][MAXN][5];

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> grid[i][j];
        }
    }

    memset(dist, -1, sizeof dist);
    dist[N - 1][0][0] = grid[N - 1][0];
    for (int r = N - 1; r >= 0; r--){
        for (int c = 0; c < N; c++){
            if (r == N - 1 && c == 0) continue;
            vector<int> d;

            if (r < N - 1){
                for (int i = 0; i < 5; i++){
                    if (dist[r + 1][c][i] != -1){
                        d.push_back(dist[r + 1][c][i]);
                    }
                }
            }

            if (c > 0){
                for (int i = 0; i < 5; i++){
                    if (dist[r][c - 1][i] != -1){
                        d.push_back(dist[r][c - 1][i]);
                    }
                }
            }

            sort(d.begin(), d.end(), greater<int>());

            for (int i = 0; i < min(5, (int)(d.size())); i++){
                dist[r][c][i] = d[i] + grid[r][c];
            }
        }
    }

    for (int i = 0; i < 5; i++){
        cout << dist[0][N - 1][i] << endl;
    }
}

