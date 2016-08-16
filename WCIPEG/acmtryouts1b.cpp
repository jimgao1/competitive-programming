
#include <bits/stdc++.h>

#define MAXN 5

using namespace std;

int T, N, a[MAXN], s[MAXN], o[MAXN];

int gcd(int a, int b){
    return (b == 0 ? a : gcd(b, a % b));
}

int lcm(int a, int b){
    return abs(a * b) / gcd(a, b);
}

int main(){
    cin >> T;
    while(T--) {
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> a[i] >> s[i] >> o[i];

        int cycle = 1;
        for (int i = 0; i < N; i++)
            cycle = lcm(cycle, a[i] + s[i]);

        bool found = false;
        for (int i = 0; i < 2 * cycle; i++) {
            bool flag = true;
            for (int j = 0; j < N; j++) {
                if ((i + o[j]) % (a[j] + s[j]) < a[j]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                printf("%d\n", i);
                found = true;
                break;
            }
        }

        if (!found) printf("Foxen are too powerful\n");
    }
}
