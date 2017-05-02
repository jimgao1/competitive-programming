
#include <bits/stdc++.h>

#define MAXN 20

using namespace std;

void extended_gcd(int a, int b, int &x, int &y){
    if (b == 0){
        x = 1, y = 0;
    } else {
        extended_gcd(b, a % b, x, y);
        int tmp = x;
        x = y;
        y = tmp - a / b * y;
    }
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int N, C[MAXN], P[MAXN], L[MAXN];

bool test(int M){
    for (int i = 0; i < N; i++){
        for (int j = i + 1; j < N; j++){
            int a = P[i] - P[j], b = M, c = C[j] - C[i];
            int x, y, g = gcd(a, b);

            if (c % g == 0){
                a = a / g, b = b / g, c = c / g;
                extended_gcd(a, b, x, y);

                b = abs(b);
                x = ((c * x) % b + b) % b;
                if (!x) x += b;

                if (x <= min(L[i], L[j])) return false;
            }
        }
    }

    return true;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int bound = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> C[i] >> P[i] >> L[i];
        bound = max(bound, C[i]);
    }

    for (int M = bound; ; M++){
        if (test(M)){
            cout << M << "\n";
            break;
        }
    }
}
