#include <bits/stdc++.h>

using namespace std;

inline bool getBit(int n, int idx) { return n & (1 << idx); }

int N, A, ans = 0, range[7];
bool grid[7][7], visited[7][7], r[7], c[7];

void dfs(int cur){
    if (cur == N){
        int cnt = 0;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (visited[i][j] && grid[i][j]) cnt++;
            }
        }

        ans = max(ans, cnt);

        return;
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (r[i] || c[j] || !grid[i][j]) continue;

            if (i - range[cur] + 1 < 0 || i + range[cur] - 1 >= N) continue;
            if (j - range[cur] + 1 < 0 || j + range[cur] - 1 >= N) continue;

            int v2[7][7];

            for (int k = 0; k < N; k++){
                for (int l = 0; l < N; l++){
                    v2[k][l] = visited[k][l];
                }
            }

            for (int ki = i - range[cur] + 1; ki <= i + range[cur] - 1; ki++){
                for (int kj = j - range[cur] + 1; kj <= j + range[cur] - 1; kj++){
                    if (!visited[ki][kj] && grid[ki][kj]){
                        visited[ki][kj] = true;
                    }
                }
            }

            r[i] = true, c[j] = true;

            dfs(cur + 1);

            r[i] = false, c[j] = false;

            for (int k = 0; k < N; k++){
                for (int l = 0; l < N; l++){
                    visited[k][l] = v2[k][l];
                }
            }
        }
    }

    dfs(cur + 1);
}

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            int x;
            scanf("%d", &x);
            grid[i][j] = (x == 1);
        }
    }
    scanf("%d", &A);
    for (int i = 0; i < N; i++) scanf("%d", &range[i]);

    dfs(0);

    printf("%d\n", ans);
}
