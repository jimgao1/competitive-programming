
#include <bits/stdc++.h>

#define MAXN 1000006
#define ll long long

using namespace std;

int bound;
bool fucked[MAXN];
unordered_set<int> primes;
vector<int> dick, fucker;

void precompute() {
    for (int i = 5; i <= MAXN; i += 4) {
        if (!fucked[i]) {
            primes.insert(i);
            fucker.push_back(i);

            for (int j = i * 2; j <= MAXN; j += i) {
                fucked[j] = true;
            }
        }
    }

    for (int i = 0; i < fucker.size() && fucker[i] <= MAXN; i++) {
        if ((ll) fucker[i] * fucker[i] >= MAXN) break;
        for (int j = i; j < fucker.size() && fucker[j] <= MAXN; j++) {
            ll ass = (ll)fucker[i] * fucker[j];
            if (ass >= MAXN) break;

            dick.push_back((int)ass);
        }
    }

    sort(dick.begin(), dick.end());
    dick.erase(unique(dick.begin(), dick.end()), dick.end());
}

void solve() {
    int n = upper_bound(dick.begin(), dick.end(), bound) - dick.begin();
    printf("%d %d\n", bound, n);
}

int main() {
    precompute();
    while (true) {
        cin >> bound;
        if (bound == 0) break;
        solve();
    }
}
