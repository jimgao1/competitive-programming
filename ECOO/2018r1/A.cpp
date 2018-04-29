
#include <bits/stdc++.h>

using namespace std;

int T, N;

void solve() {
    int last = 0;

    cin >> T >> N;
    for (int i = 1; i <= N; i++) {
        char c;
        cin >> c;
        if (c == 'B') {
            if (i > last) {
                last = i + T - 1;
            } else {
                last += T;
            }
        }
    }

    cout << max(0, last - N) << endl;
}

int main() {
    freopen("/tmp/DATA11.txt", "r", stdin);

    int cases = 10;
    while (cases--) {
        solve();
    }
}
