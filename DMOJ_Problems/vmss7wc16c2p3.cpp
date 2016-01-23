
#include <bits/stdc++.h>

using namespace std;

int N, M, ans = 0, idx[1000010], idx2[1000010], dp[1000010];

int main(){
    scanf("%d", &N);
    for (int i = 1, x; i <= N; i++){
        scanf("%d", &x);
        idx[x] = i;
    }
    scanf("%d", &M);
    for (int i = 1, x; i <= M; i++){
        scanf("%d", &x);
        idx2[i] = idx[x];
    }

    for (int i = 1; i <= M; i++){
        if (idx2[i] == 0) continue;

        if (ans == 0 || idx2[i] > dp[ans - 1]) {
            dp[ans++] = idx2[i];
        } else {
            int p = lower_bound(dp, dp + ans, idx2[i]) - dp;
            dp[p] = idx2[i];
        }
    }

    printf("%d\n", ans);
}
