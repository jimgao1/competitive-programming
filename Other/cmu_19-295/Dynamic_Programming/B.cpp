
#include <bits/stdc++.h>

#define MAXN 100005
#define MOD 1000000007
#define ll long long

using namespace std;

int T, K;
ll dp[MAXN];

int main() {
    cin >> T >> K;

    dp[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        dp[i] = (dp[i] + dp[i - 1]) % MOD;
        if (i >= K) dp[i] = (dp[i] + dp[i - K]) % MOD;
    }

    for (int i = 1; i < MAXN; i++) dp[i] = (dp[i] + dp[i - 1]) % MOD;

    for (int i = 0, a, b; i < T; i++) {
        cin >> a >> b;
        printf("%lld\n", (dp[b] - dp[a - 1] + MOD) % MOD);
    }
}
