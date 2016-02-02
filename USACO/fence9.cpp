/*
ID: jim_yub1
LANG: C++
TASK: fence9
*/

#include <bits/stdc++.h>

using namespace std;

int ans, border = 0, n, m, p;

inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
inline int nceil(double a) { return (a - (int)(a) > 0.3) ? a + 1 : a; }

int main(){
    freopen("fence9.in", "r", stdin);
    freopen("fence9.out", "w", stdout);

    scanf("%d%d%d", &n, &m, &p);

    //step 1: calculate the area
    double a = p, b = sqrt(n * n + m * m), c = sqrt((n - p) * (n - p) + m * m);
    double s = (a + b + c) / 2;
    int area = sqrt( ( a + ( b + c ) ) * ( c - ( a - b ) ) * ( c + ( a - b ) ) * ( a + ( b - c ) ) ) / 4;

    //cout << "area = " << area << endl;

    //step 2: calculate the border points
    border += p;
    border += gcd(n, m);
    border += gcd(abs(n - p), m);

    //cout << "border = " << border << endl;

    //step 3: calculate interior points
    ans = area - nceil(border / 2.0) + 1;

    printf("%d\n", ans);
}
