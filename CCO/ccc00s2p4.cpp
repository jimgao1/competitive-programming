
#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int N, M, P, matrix[MAXN][MAXN];

int main(){
    memset(matrix, 0x3f, sizeof matrix);

    cin >> N >> M >> P;
    for (int i = 0, a, b, w; i < M; i++){
        cin >> a >> b >> w;
        matrix[a - 1][b - 1] = matrix[b - 1][a - 1] = w;
    }

    for (int k = 0; k < N; k++){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                matrix[i][j] = min(matrix[i][j],
                    matrix[i][k] + matrix[k][j]);
            }
        }
    }

    for (int i = 0, a, b; i < P; i++){
        cin >> a >> b;
        cout << matrix[a - 1][b - 1] << endl;
    }
}
