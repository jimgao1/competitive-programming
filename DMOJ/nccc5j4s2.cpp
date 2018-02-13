#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

int N, A[MAXN];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (A[j] < A[j + 1]) {
                swap(A[j], A[j + 1]);
                ans++;
            }
        }
    }

    cout << ans << endl;
}
