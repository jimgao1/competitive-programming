/*
ID: jim_yub1
LANG: C++11
TASK: theme
*/

#include <bits/stdc++.h>

#define MAXN 5001

using namespace std;

int N, A[MAXN], B[MAXN];

int main() {
    freopen("theme.in", "r", stdin);
    freopen("theme.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) B[i] = A[i + 1] - A[i];
    N--;

    int ans = 0;
    for (int i = 0; i + ans < N; i++) {
        for (int j = i + ans; j + ans < N; j++) {
            for (int k = 0; j + k < N && i + k < j; k++) {
                if (B[i + k] == B[j + k]) {

                    if (i + k < j - 1)
                        ans = max(ans, k + 1);
                    else
                        ans = max(ans, k);
                } else {
                    break;
                }
            }
        }
    }

    cout << (ans < 4 ? 0 : ans + 1) << endl;
}
