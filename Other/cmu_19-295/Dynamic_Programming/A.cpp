
#include <bits/stdc++.h>

#define ll long long
#define MAXN 100005

using namespace std;

int N;
ll freq[MAXN], dp[MAXN];

ll calc(int idx) {
    if (idx >= MAXN) return 0;
    if (dp[idx] != -1) return dp[idx];

    return dp[idx] = max(freq[idx] * idx + calc(idx + 2), calc(idx + 1));
}

int main() {
    cin >> N;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        freq[x]++;
    }

    memset(dp, -1, sizeof dp);

    cout << calc(0) << endl;
}
