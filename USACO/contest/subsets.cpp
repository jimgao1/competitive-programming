
#include <bits/stdc++.h>

#define MAXN 21
#define ll long long

using namespace std;

int N;
bool used[1 << MAXN + 1];
ll ans = 0, M[MAXN];
vector<ll> A, B;
unordered_map<ll, vector<pair<ll, int>>> mp;


void calc(int cur, ll sum, int mask) {
    if (cur == A.size()) {
        mp[sum].push_back(make_pair(sum, mask));
        return;
    }

    for (int i = -1; i <= 1; i++) {
        int nmask = mask;
        if (i != 0) nmask |= (1 << cur);
        calc(cur + 1, sum + i * A[cur], nmask);
    }
}

void calc2(int cur, ll sum, int mask) {
    if (cur == B.size()) {
        for (pair<ll, int> i : mp[-sum]) {
            if (!used[i.second | mask]) ans++;
            used[i.second | mask] = 1;
        }
        return;
    }

    for (int i = -1; i <= 1; i++) {
        int nmask = mask;
        if (i != 0) nmask |= (1 << (cur + A.size()));
        calc2(cur + 1, sum + i * B[cur], nmask);
    }
}

int main() {
//    freopen("subsets.in", "r", stdin);
//    freopen("subsets.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> M[i];
        if (i % 2)
            A.push_back(M[i]);
        else
            B.push_back(M[i]);
    }

    calc(0, 0, 0);
    calc2(0, 0, 0);

    cout << ans - 1 << "\n";
}
