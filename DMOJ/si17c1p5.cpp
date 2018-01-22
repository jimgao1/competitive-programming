
#include <bits/stdc++.h>

#define ull unsigned long long
#define MOD (1000000000ULL)

using namespace std;

ull mulmod(ull a, ull b) {
    ull m = MOD;
    ull res = 0;
    while (a != 0) {
        if (a & 1ULL) res = (res + b) % m;
        a >>= 1ULL;
        b = (b << 1ULL) % m;
    }
    return res;
}

struct matrix {
    ull num[2][2];
    matrix() {
        memset(num, 0, sizeof num);
    }

    matrix(int a, int b, int c, int d) {
        num[0][0] = a;
        num[0][1] = b;
        num[1][0] = c;
        num[1][1] = d;
    }

    matrix multiply(matrix m) {
        matrix A;
        A.num[0][0] = (mulmod(num[0][0], m.num[0][0]) + mulmod(num[0][1], m.num[1][0])) % MOD;
        A.num[0][1] = (mulmod(num[0][0], m.num[0][1]) + mulmod(num[0][1], m.num[1][1])) % MOD;
        A.num[1][0] = (mulmod(num[1][0], m.num[0][0]) + mulmod(num[1][1], m.num[1][0])) % MOD;
        A.num[1][1] = (mulmod(num[1][0], m.num[0][1]) + mulmod(num[1][1], m.num[1][1])) % MOD;
        return A;
    }
};

matrix base(1, 1, 1, 0);

matrix mpow(ull x) {
    if (x == 1) return base;
    matrix S = mpow(x / 2);
    return (x & 1) ? S.multiply(S).multiply(base) : S.multiply(S);
}

ull fib(ull N) {
    return (mpow(N + 1).num[0][1]) % MOD;
}

ull A, B, N;

int main() {
    cin >> A >> B >> N;

    if (N == 0) {
        cout << A << endl;
    } else if (N == 1) {
        cout << B << endl;
    } else {
        ull a = mulmod(fib(N - 2), A) % MOD;
        ull b = mulmod(fib(N - 1), B) % MOD;
        cout << (a + b) % MOD << endl;
    }
}
