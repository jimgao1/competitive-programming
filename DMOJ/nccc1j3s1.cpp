#include <bits/stdc++.h>

using namespace std;

double K, P, X;

double eval(double M) {
    return M * X + K * P / M;
}

int main() {
    cin >> K >> P >> X;
    double M = sqrt(K * P / X);
    double m1 = ceil(M), m2 = floor(M);

    printf("%.3f\n", min(eval(m1), eval(m2)));
}
