#include <bits/stdc++.h>

#define MAXN 100005
#define ll long long

using namespace std;

int N, P[MAXN], dset[MAXN], dsize[MAXN];
bool visited[MAXN];
vector<ll> v;

ll fucker(int node) {
    ll fuck = 0;
    while (true) {
        if (visited[node]) break;
        visited[node] = true;
        fuck++;

        node = P[node];
    }
    return fuck;
}

ll fuckit(ll n) {
    return n * n;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            ll a = fucker(i);
            v.push_back(a);
        }
    }

    sort(v.begin(), v.end(), [](ll a, ll b) { return a > b; });
    ll ans = 0;
    if (v.size() >= 2) {
        ans += fuckit(v[0] + v[1]);
        for (int i = 2; i < v.size(); i++) ans += fuckit(v[i]);
    } else {
        ans = fuckit(v[0]);
    }

    cout << ans << endl;
}
