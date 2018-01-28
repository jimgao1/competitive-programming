
#include <bits/stdc++.h>

#define MAXN 20
#define ll long long

using namespace std;

int N, K;
ll dp[MAXN][2];

ll calc(int cur, bool zero) {
    if (cur == N) return 1;
    if (dp[cur][zero] != -1) return dp[cur][zero];

    ll ans = 0;
    if (zero) {
        ans = calc(cur + 1, 0) + (K - 1) * calc(cur + 1, 1);
    } else {
        ans = (K - 1) * calc(cur + 1, 1);
    }

    return dp[cur][zero] = ans;
}

int main() {
    cin >> N >> K;
    memset(dp, -1, sizeof dp);

    cout << calc(0, 0) << endl;
}
