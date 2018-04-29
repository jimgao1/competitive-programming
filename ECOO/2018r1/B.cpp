
#include <bits/stdc++.h>

#define MAXN 1000

using namespace std;

int N;
vector<int> ids;
set<int> S[MAXN];

void init() {
    ids.clear();
    for (int i = 0; i < MAXN; i++) S[i].clear();
}

void solve() {
    cin >> N;
    int minVal = 1e9;
    for (int i = 0, x, sz; i < N; i++) {
        cin >> x >> sz;
        ids.push_back(x);
        for (int j = 0, xx; j < sz; j++) {
            cin >> xx;
            minVal = min(minVal, xx);
            S[x].insert(xx);
        }
    }

    printf("%d ", minVal);

    vector<int> ans;
    for (int curSet : ids) {
        if (S[curSet].find(minVal) != S[curSet].end()) {
            ans.push_back(curSet);
        }
    }

    sort(ans.begin(), ans.end());

    printf("{");
    for (int i = 0; i < ans.size(); i++) {
        if (i > 0) printf(",");
        printf("%d", ans[i]);
    }
    printf("}\n");
}

int main() {
    freopen("/tmp/DATA21.txt", "r", stdin);

    int cases = 10;
    while (cases--) {
        init();
        solve();
    }
}

