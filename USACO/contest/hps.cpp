
#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

int N, K, P[MAXN], dp[MAXN][23][4];

int win(int a, int b) {
    if (b == 0) return (a == 1 ? 1 : 0);
    if (b == 1) return (a == 2 ? 1 : 0);
    return (a == 0 ? 1 : 0);
}

int calc(int cur, int changes, int state) {
    if (cur == N) return 0;
    if (changes > K) return -1e9;
    if (dp[cur][changes][state] != -1) return dp[cur][changes][state];

    int ans = calc(cur + 1, changes, state);
    if (changes < K) {
        for (int i = 0; i < 3; i++) {
            if (i != state) {
                ans = max(ans, calc(cur + 1, changes + 1, i));
            }
        }
    }
    return dp[cur][changes][state] = ans + win(state, P[cur]);
}

int main() {
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        P[i] = (str == "H" ? 0 : (str == "P" ? 1 : 2));
    }

    memset(dp, -1, sizeof dp);
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        ans = max(ans, calc(0, 0, i));
    }

    cout << ans << endl;
}
