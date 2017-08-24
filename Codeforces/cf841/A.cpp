#include <bits/stdc++.h>

using namespace std;

int N, K, f[26];
string str;

int main() {
    cin >> N >> K;
    cin >> str;
    for (int i = 0; i < N; i++) {
        f[str[i] - 'a'] ++;
    }

    for (int i = 0; i < 26; i++){
        if (f[i] > K){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
}
