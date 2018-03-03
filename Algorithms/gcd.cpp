
#include <bits/stdc++.h>

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


