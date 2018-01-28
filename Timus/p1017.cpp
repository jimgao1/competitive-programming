
#include <bits/stdc++.h>

#define MAXN 501
#define ll long long

using namespace std;

int N;
ll dp[MAXN][MAXN];

ll calc(int remain, int last) {
    if (remain == 0) return 1;
    if (dp[remain][last] != -1) return dp[remain][last];
    ll ans = 0;
    for (int i = last + 1; i <= remain; i++) {
        ans += calc(remain - i, i);
    }
    return dp[remain][last] = ans;
}

int main() {
    cin >> N;
    memset(dp, -1, sizeof dp);

    ll ans = 0;
    for (int i = 1; i < N / 2.0; i++) {
        ans += calc(N - i, i);
    }

    cout << ans << endl;
}
