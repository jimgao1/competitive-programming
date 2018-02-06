
#include <bits/stdc++.h>

#define MAXN 100005
#define ll long long

using namespace std;

int N, A[2][MAXN], tmp[MAXN], bit[MAXN];
unordered_map<int, int> mp;

void update(int i, int val) {
    i++;
    while (i < MAXN) {
        bit[i] += val;
        i += (i & -i);
    }
}

int query(int i) {
    int ans = 0;
    i++;
    while (i > 0) {
        ans += bit[i];
        i -= (i & -i);
    }
    return ans;
}

ll inversions(int idx) {
    mp.clear();
    memset(tmp, 0, sizeof tmp);
    memset(bit, 0, sizeof bit);

    for (int i = 0; i < N; i++) mp[A[1 - idx][i]] = i;
    for (int i = 0; i < N; i++) tmp[i] = mp[A[idx][i]];

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += i - query(tmp[i]);
        update(tmp[i], 1);
    }
    return ans;
}

int main() {
    freopen("mincross.in", "r", stdin);
    freopen("mincross.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    ll ans = 1e18;
    for (int idx = 0; idx < 2; idx++) {
        ll v = inversions(idx);
        ans = min(ans, v);
        for (int i = N - 1; i >= 0; i--) {
            v += ((tmp[i] + 1) * 2 - N - 1);
            ans = min(ans, v);
        }
    }

    cout << ans << endl;
}
