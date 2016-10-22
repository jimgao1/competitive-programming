
#include <cstdio>

#define INF 0x3f3f3f3f
#define MAXN 10005

using namespace std;

int N;
double dp[MAXN], val[MAXN];

int main(){
    for (int i = 0; i < MAXN; i++) dp[i] = INF;

    scanf("%d", &N);
    for (int i = 1, x; i <= N; i++) {
        scanf("%d", &x);
        val[i] = (double)(x);
    }

    val[0] = dp[0] = 0;
    for (int i = 1; i <= N + 1; i++){
        dp[i] = val[i] + dp[i - 1];
        if (i - 2 >= 0)
            dp[i] = min(dp[i], dp[i - 2] + (val[i] + val[i - 1] - min(val[i], val[i - 1]) / 2.0));
        if (i - 3 >= 0)
            dp[i] = min(dp[i], dp[i - 3] + (val[i] + val[i - 1] + val[i - 2] - min(val[i], min(val[i - 1], val[i - 2]))));

        //printf("i = %d, val[i] = %.1f, dp[i] = %.1f\n", i, val[i], dp[i]);
    }

    printf("%.1f\n", dp[N + 1]);
}

