
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return gcd(a, b) ? (a / gcd(a, b) * b) : 0;
}

struct fraction{
    int numerator, denominator;

    fraction(int a, int b){
        numerator = a, denominator = b;
    }

    fraction simplify(fraction f){
        int g = gcd(f.numerator, f.denominator);
        return fraction(f.numerator / g, f.denominator / g);
    }

    fraction add(fraction f){
        int l = lcm(denominator, f.denominator);
        numerator *= (l / denominator);
        numerator += f.numerator * (l / f.denominator);

        return simplify(fraction(numerator, l));
    }

    void print(){
        if (denominator != 1)
            printf("%d %d\n", numerator, denominator);
        else
            printf("%d\n", numerator);
    }
};

int main(){
    for (int i = 0; i < 5; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        fraction(a, b).add(fraction(c, d)).print();
    }
}
