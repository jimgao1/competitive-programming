o
#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int N, dp[MAXN][MAXN], num[MAXN], sum[MAXN];

int gsum(int i, int j) { if (i == 0) return sum[j]; return sum[j] - sum[i - 1]; }

int f(int i, int j){
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int ans = -0x3f3f3f3f;
    for (int k = i; k <= j; k++){
        ans = max(ans, gsum(i, k) - f(k + 1, j));
    }

    for (int k = j; k >= i; k--){
        ans = max(ans, gsum(k, j) - f(i, k - 1));
    }

    return dp[i][j] = ans;
}

int main(){
    while(true) {
        cin >> N;

        if (N == 0) break;
        memset(num, 0, sizeof num);
        memset(sum, 0, sizeof sum);
        memset(dp, -1, sizeof dp);

        for (int i = 0; i < N; i++) cin >> num[i];
        sum[0] = num[0];
        for (int i = 1; i < N; i++) sum[i] = sum[i - 1] + num[i];

        cout << f(0, N - 1) << endl;
    }
}
