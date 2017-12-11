
#include <bits/stdc++.h>

#define ll long long
#define MAXN 1000006

using namespace std;

int N, P, bit[MAXN];
ll A[MAXN];
vector<pair<ll, int>> order;

void update(int i, int val) {
    i++;
    while (i < MAXN) {
        bit[i] += val;
        i += (i & -i);
    }
}

int query(int i) {
    i++;
    int sum = 0;
    while (i > 0) {
        sum += bit[i];
        i -= (i & -i);
    }
    return sum;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> P;

    for (int i = 0; i < N; i++) {
        A[i] -= P;
        if (i > 0) A[i] += A[i - 1];

        order.push_back(make_pair(A[i], i + 1));
    }

    order.push_back(make_pair(0, 0));

    sort(order.begin(), order.end());

    ll ans = 0;
    for (pair<ll, int> i : order) {
        ans += query(i.second);
        update(i.second, 1);
    }

    cout << ans << endl;
}
