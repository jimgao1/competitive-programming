
#include <bits/stdc++.h>

#define MAXN 100005
#define ll long long

using namespace std;

int N;
ll A[MAXN], B[MAXN], dp[MAXN];
deque<int> q;

double f(int i, int j) {
    return (double) (dp[j] - dp[i]) / (B[i] - B[j]);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    memset(dp, 0x3f, sizeof dp);

    dp[0] = 0;
    q.push_back(0);

    int last = 0;
    for (int i = 1; i < N; i++) {
        while (q.size() >= 2) {
            if (f(q[0], q[1]) <= A[i]) {
                q.pop_front();
            } else {
                break;
            }
        }

        dp[i] = dp[q[0]] + 1LL * A[i] * B[q[0]];

        while (q.size() >= 2) {
            if (f(q[q.size() - 2], q[q.size() - 1]) >= f(q[q.size() - 1], i)) {
                q.pop_back();
            } else {
                break;
            }
        }

        q.push_back(i);
    }

    cout << dp[N - 1] << "\n";
}

