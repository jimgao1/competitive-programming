
#include <bits/stdc++.h>

#define ll long long

#define MAXN 101
#define MOD 1000000007

using namespace std;

int N, K, D;
ll dp[MAXN][2];

ll calc(int sz, int d) {
    if (sz == 0) return d;
    if (dp[sz][d] != -1) return dp[sz][d];

    ll ans = 0;
    for (int i = 1; i <= min(K, sz); i++) {
        ans = (ans + calc(sz - i, i >= D ? 1 : d)) % MOD;
    }

    return dp[sz][d] = ans;
}

int main() {
    cin >> N >> K >> D;

    memset(dp, -1, sizeof dp);
    cout << calc(N, 0) << endl;
}
