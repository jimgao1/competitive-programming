
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int N, M, matrix[101][101], tcnt = 0, cnt = 0;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while(true){
        N = 0, M = 0, cnt = 0;
        memset(matrix, 0x3f, sizeof matrix);

        while(true){
            int a, b;
            scanf("%d%d", &a, &b);

            if (a == 0 && b == 0) break;

            M++;
            matrix[a - 1][b - 1] = 1;
            //matrix[b - 1][a - 1] = 1;
        }

        if (M == 0) break;

        for (int k = 0; k < 100; k++)
            for (int i = 0; i < 100; i++)
                for (int j = 0; j < 100; j++)
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);

        double sum = 0;
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++)
                if (matrix[i][j] != INF && i != j)
                    sum += matrix[i][j], cnt++;


        printf("Case %d: average length between pages = %.3f clicks\n", ++tcnt, sum / cnt);
    }
}
