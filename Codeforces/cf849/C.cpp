#include <bits/stdc++.h>

using namespace std;

int f(int n) {
    return n * (n - 1) / 2;
}

int ff(int n) {
    int b = floor(0.5 + sqrt(1 + n * 8) / 2.0);
    return b;
}

void solve() {
    int K;
    cin >> K;

    if (K == 0) {
        cout << "a" << endl;
        return;
    }

    int c = 0;
    while (K > 0) {
        int n = ff(K);
        K -= n * (n - 1) / 2;
        for (int i = 0; i < n; i++)
            printf("%c", 'a' + c);
        c++;
    }

    printf("\n");
}

int aa(int l) {
    if (l == 1) return 1;
    int x = (1 * (l - 1)) + aa(1) + aa(l - 1);
    for (int i = 1; i < l; i++){
        int xx = i * (l - i) + aa(i) + aa(l - i);
        if (xx != x) printf("fuck!");
    }
    return x;
}

//int fr[26];
//
//int calc(string str) {
//    memset(fr, 0, sizeof fr);
//    // [0,i) U str[i]
//    int ans = 0;
//    for (int i = 0; i < str.size(); i++) {
//        ans += fr[str[i] - 'a'];
//        fr[str[i] - 'a']++;
//    }
//    return ans;
//}

int main() {
    solve();
}
