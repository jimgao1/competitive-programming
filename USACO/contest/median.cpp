
#include <bits/stdc++.h>

#define ll long long
#define MAXN 100001

using namespace std;

int N, X;
ll A[MAXN], bit[2 * MAXN];

ll query(int i) {
    ll ans = 0;
    while (i > 0) {
        ans += bit[i];
        i -= (i & -i);
    }
    return ans;
}

void update(int i, int val) {
    while(i < 2 * MAXN){
        bit[i] += val;
        i += (i & -i);
    }
}

int main() {
    cin >> N >> X;
    for (int i = 0; i < N; i++){
        ll n;
        cin >> n;
        if (n >= X)
            A[i] = 1;
        else
            A[i] = -1;
    }

    update(MAXN, 1);

    ll ans = 0;
    for (int i = 0; i < N; i++){
        if (i > 0) A[i] += A[i - 1];
        ans += query(A[i] + MAXN);
        update(A[i] + MAXN, 1);
    }

    cout << ans << endl;
}
