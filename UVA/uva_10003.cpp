
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int L, N, len[52], dp[52][52], ans = 0;

int calc(int a, int b){
    if (a > b) return INF;
    if (a + 1 == b) return 0;
    if (a == b) return 0;

    if (dp[a][b] != -1) return dp[a][b];

    int ans = INF;

    for (int i = a + 1; i < b; i++){
        ans = min(ans, calc(a, i) + calc(i, b));
    }

    dp[a][b] = (ans == INF ? INF : ans + (len[b] - len[a]));
    return dp[a][b];
}

int main(){
    while(true){
        memset(dp, -1, sizeof dp);

        scanf("%d", &L);
        if (L == 0) break;

        scanf("%d", &N);
        len[0] = 0, len[N + 1] = L;
        for (int i = 1; i <= N; i++) scanf("%d", &len[i]);

        printf("The minimum cutting is %d.\n", calc(0, N + 1));
    }

}
