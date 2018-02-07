
#include <bits/stdc++.h>

#define ll long long
#define MAXN 100005
#define LOGMAXN 17

using namespace std;

ll N, M, F[MAXN], S[MAXN], segtree[MAXN * 4], segtree2[MAXN * 4];

void build(int idx, int l, int r) {
    if (l == r) {
        segtree[idx] = F[l];
        segtree2[idx] = S[l];
        return;
    }
    int mid = (l + r) / 2;
    build(idx * 2, l, mid);
    build(idx * 2 + 1, mid + 1, r);

    segtree[idx] = min((ll) 4e18, segtree[idx * 2] + segtree[idx * 2 + 1]);
    segtree2[idx] = max(segtree2[idx * 2], segtree2[idx * 2 + 1]);
}

ll query(int idx, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;
    if (ql <= l && qr >= r) return min((ll) 4e18, segtree[idx]);

    int mid = (l + r) / 2;
    return min((ll) 4e18, query(idx * 2, l, mid, ql, qr)
                          + query(idx * 2 + 1, mid + 1, r, ql, qr));
}

ll query2(int idx, int l, int r, int ql, int qr){
    if (l > qr || r < ql) return 0;
    if (ql <= l && qr >= r) return segtree2[idx];

    int mid = (l + r) / 2;
    return max(query2(idx * 2, l, mid, ql, qr),
               query2(idx * 2 + 1, mid + 1, r, ql, qr));
}

int main() {
//    freopen("/home/jim/Downloads/fuckshit/2.in", "r", stdin);

    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> F[i] >> S[i];
    }

    build(1, 0, N - 1);

    ll ans = 1e18;
    for (int i = 0; i < N; i++) {
        int low = i, high = N - 1, a = 1e9;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (query(1, 0, N - 1, i, mid) < M) {
                low = mid + 1;
            } else {
                a = min(a, mid);
                high = mid - 1;
            }
        }

        if (a == 1e9) continue;
        ans = min(ans, query2(1, 0, N - 1, i, a));
    }

    cout << ans << endl;
}
