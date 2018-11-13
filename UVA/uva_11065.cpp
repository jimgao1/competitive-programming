
#include <bits/stdc++.h>

#define MAXN 61
#define ll long long

using namespace std;

inline bool getBit(ll n, int idx) { return n & (1LL << idx); }
inline ll setBit(ll n, int idx) { return n | (1LL << idx); }

int T, N, M, ans1 = 0, ans2 = 0;
ll adj[MAXN];

void calc(int cur, int cnt, ll mask) {
    if (mask == (1LL << N) - 1) {
        ans1++;
        ans2 = max(ans2, cnt);

        return;
    }

    for (int i = cur; i < N; i++) {
        if (!getBit(mask, i)) {
            calc(i, cnt + 1, mask | adj[i] | (1LL << i));
        }
    }
}

void solve() {
    ans1 = ans2 = 0;
    memset(adj, 0, sizeof adj);

    cin >> N >> M;
    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        adj[a] = setBit(adj[a], b);
        adj[b] = setBit(adj[b], a);
    }

    calc(0, 0, 0);

    printf("%d\n%d\n", ans1, ans2);
}

int main() {
    cin >> T;
    while(T--) solve();
}
