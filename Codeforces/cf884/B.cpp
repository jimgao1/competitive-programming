#include <bits/stdc++.h>

#define ll long long

using namespace std;

int N;
ll x, sum = 0;

int main() {
    cin >> N >> x;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        sum += x;
        sum++;
    }
    sum--;

    if (sum == x) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
