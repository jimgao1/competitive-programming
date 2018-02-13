#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int N, X, A[MAXN];

int main() {
    cin >> N >> X;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A + N);

    int ans = 0;
    for (int i = 1; i < N - 1; i++) {
        if (A[i] == X) {
            ans += i * (N - i - 1);
        }
    }

    cout << ans << endl;
}
