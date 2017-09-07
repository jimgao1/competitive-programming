#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int N;

int main() {
    cin >> N;
    int a, b;
    double m = 0;
    for (double i = 1; i < N; i++) {
        if (i >= N - i) break;
        if (gcd(i, N - i) != 1) continue;
        if (i / (N - i) > m) {
            m = i / (N - i);
            a = i;
            b = N - i;
        }
    }

    printf("%d %d\n", a, b);
}
