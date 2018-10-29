#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> II;

LL Count(LL n, int k) {
    LL ans = 0;
    while (n) {
        ans += n / k;
        n /= k;
    }
    return ans;
}

LL TrailingZero(LL n) {
    return min(Count(n, 2), Count(n, 5));
}

int main() {
    int a, b;
    cin >> a >> b;

    LL l, r, x, y;
    l = 1, r = 1e15; x = -1;
    while (l <= r) {
        LL m = (l + r) >> 1;
        if (TrailingZero(m) >= a) {
            x = m;
            r = m - 1;
        }
        else l = m + 1;
    }


    l = 1, r = 1e15; y = -1;
    while (l <= r) {
        LL m = (l + r) >> 1;
        if (TrailingZero(m) <= b) {
            y = m;
            l = m + 1;
        }
        else r = m - 1;
    }

    cout << y - x + 1;
    return 0;
}
