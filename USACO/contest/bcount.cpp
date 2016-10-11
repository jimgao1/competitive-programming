
#include <cstdio>

#define MAXN 100010

using namespace std;

int N, Q, sum[3][MAXN];

int main(){
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);

    scanf("%d%d", &N, &Q);
    for (int i = 1, x; i <= N; i++){
        scanf("%d", &x);
        sum[x - 1][i] ++;
    }

    for (int i = 0; i < 3; i++){
        for (int j = 1; j < MAXN; j++){
            sum[i][j] += sum[i][j - 1];
        }
    }

    for (int i = 0, a, b; i < Q; i++){
        scanf("%d%d", &a, &b);
        printf("%d %d %d\n", sum[0][b] - sum[0][a - 1], sum[1][b] - sum[1][a - 1], sum[2][b] - sum[2][a - 1]);
    }
};
