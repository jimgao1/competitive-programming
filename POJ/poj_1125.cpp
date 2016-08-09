
#include <bits/stdc++.h>

#define MAXN 101
#define INF 0x3f3f3f3f

using namespace std;

int N, matrix[MAXN][MAXN];

int main(){
    while(true) {
        memset(matrix, 0x3f, sizeof matrix);
        cin >> N;

        if (N == 0) break;

        for (int i = 0; i < N; i++)
            matrix[i][i] = 0;
        for (int i = 0, c; i < N; i++) {
            cin >> c;
            for (int j = 0, a, b; j < c; j++) {
                cin >> a >> b;
                matrix[i][a - 1] = b;
            }
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (matrix[i][j] > matrix[i][k] + matrix[k][j])
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                }
            }
        }

        int ans1 = -1, ans2 = INF;
        for (int i = 0; i < N; i++) {
            int tmp = 0;
            for (int j = 0; j < N; j++) {
                tmp = max(tmp, matrix[i][j]);
            }

            if (tmp < ans2) {
                ans1 = i, ans2 = tmp;
            }
        }

        if (ans2 == INF) {
            printf("disjoint\n");
        } else {
            printf("%d %d\n", ans1 + 1, ans2);
        }
    }
}