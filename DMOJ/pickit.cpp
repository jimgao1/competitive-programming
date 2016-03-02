
#include <bits/stdc++.h>

#define MAXN 201

using namespace std;

int N, num[MAXN], dp[MAXN][MAXN];

int solve(int l, int r){
    if (l == r) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int ans = 0;
    for (int i = l + 1; i <= r - 1; i++){
        ans = max(ans, num[l] + num[r] + solve(l, i) + solve(i, r) + num[i]);
    }

    dp[l][r] = ans;
    return ans;
}

int main(){
    while(true){
        memset(dp, -1, sizeof dp);

        cin >> N;

        if (N == 0) break;
        for (int i = 0; i < N; i++) cin >> num[i];

        cout << solve(0, N - 1) << endl;
    }
}
