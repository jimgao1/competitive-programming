
#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int T, N, M, s, t, matrix[MAXN][MAXN];

int main(){
    cin >> T;
    for (int c = 1; c <= T; c++){
        memset(matrix, 0x3f, sizeof matrix);

        cin >> N >> M;
        for (int i = 0, a, b; i < M; i++){
            cin >> a >> b;
            matrix[a][b] = 1;
            matrix[b][a] = 1;
        }

        for (int i = 0; i < N; i++) matrix[i][i] = 0;

        for (int k = 0; k < N; k++){
            for (int i = 0; i < N; i++){
                for (int j = 0; j < N; j++){
                    if (matrix[i][j] > matrix[i][k] + matrix[k][j]){
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }

        cin >> s >> t;

        int ans = 0;
        for (int i = 0; i < N; i++){
            ans = max(ans, matrix[s][i] + matrix[i][t]);
        }

        printf("Case %d: %d\n", c, ans);
    }
}
