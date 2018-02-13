#include <bits/stdc++.h>

#define ll long long

using namespace std;

int N, K;
vector<int> A;

int main() {
    cin >> N >> K;
    A.push_back(0);
    for (int i = 0, x; i < K; i++) {
        cin >> x;
        A.push_back(x);
    }

    ll ans = 0;
    for (int i = 1; i + 2 < A.size(); i++) {
        ans += (ll)(A[i] - A[i - 1]) * (N + 1 - A[i + 2]);
    }

    cout << ans << endl;
}
