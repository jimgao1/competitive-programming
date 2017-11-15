#include <bits/stdc++.h>

using namespace std;

int N;
long long ans = 0;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        long long c, v;
        cin >> c >> v;
        if (v > 0) ans += c;
    }
    cout << ans << endl;
}
