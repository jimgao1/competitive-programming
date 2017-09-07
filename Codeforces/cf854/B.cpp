
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll N, K;

ll min2(int a, int b) { return a < b ? a : b; }

int main() {
    cin >> N >> K;

    if (K > 0)
        printf("%lld ", min2(N - K, 1));
    else
        printf("0 ");

    ll groups = min2(K, N / 3);
    if (K * 3 < N) {
        printf("%lld\n", groups * 2);
    } else {
        printf("%lld\n", N - K);
    }
}
