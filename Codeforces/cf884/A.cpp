#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int N, T;

int main() {
    cin >> N >> T;
    int i;
    for (i = 0; i < N && T > 0; i++) {
        int x;
        cin >> x;
        T -= (86400 - x);
    }

    cout << i << endl;
}
