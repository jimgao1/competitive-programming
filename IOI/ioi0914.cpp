
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int X, Y, raisins[51][51], rsum[51][51], dp[51][51][51][51];

inline int nmin(int a, int b) { return (a < b ? a : b); }

int f(int ax, int ay, int bx, int by){

    if (dp[ax][ay][bx][by] != INF) return dp[ax][ay][bx][by];

    if (ax == bx && ay == by) return 0;

    int ans = INF;

    for (int i = ax + 1; i <= bx; i++){
        ans = nmin(ans, f(ax, ay, i - 1, by) + f(i, ay, bx, by));
    }

    for (int i = ay + 1; i <= by; i++){
        ans = nmin(ans, f(ax, ay, bx, i - 1) + f(ax, i, bx, by));
    }

    int s = 0;
    for (int i = ax; i <= bx; i++)
        for (int j = ay; j <= by; j++)
            s += raisins[i][j];

    dp[ax][ay][bx][by] = ans + s;

    return dp[ax][ay][bx][by];
}

int main(){
    scanf("%d%d", &Y, &X);
    memset(rsum, 0, sizeof rsum);
    memset(dp, 0x3f, sizeof dp);

    for (int i = 0; i < Y; i++)
        for (int j = 0; j < X; j++)
            scanf("%d", &raisins[j][i]);

    printf("%d\n", f(0, 0, X - 1, Y - 1));
}
