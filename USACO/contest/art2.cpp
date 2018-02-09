
#include <bits/stdc++.h>

#define MAXN 1000006

using namespace std;

int N, A[MAXN], L[MAXN], R[MAXN];
bool seen[MAXN];
deque<int> Q;

int main() {
    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < MAXN; i++) L[i] = N, R[i] = -1;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        seen[A[i]] = 1;
        L[A[i]] = min(L[A[i]], i);
        R[A[i]] = max(R[A[i]], i);
    }

    int ans = 0;
    for (int i = 0; i <= N; i++) {
        int c = A[i];
        if (c == 0) continue;
        if (i == L[c]) {
            Q.push_back(c);
            ans = max(ans, (int)Q.size());
        }
        if (Q.back() != c) {
            cout << -1 << endl;
            return 0;
        }
        if (i == R[c]) {
            Q.pop_back();
        }
    }

    cout << ans << endl;
}
