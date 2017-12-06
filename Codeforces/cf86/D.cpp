// owo

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define MAXN 200005
#define ll long long

using namespace std;

const int bsz = sqrt(MAXN);

struct query{
    int l, r, idx;
    query(int a, int b, int c){
        l = a, r = b, idx = c;
    }
};

int N, T, A[MAXN];
ll ans[MAXN];
vector<query> queries;
int mp[1000006];

int cl = 0, cr = -1;
ll cur_ans = 0;
void update(int l, int r) {
    while (l < cl) {
        cl--;
        cur_ans += 1LL * A[cl] * (pow(mp[A[cl]] + 1, 2) - pow(mp[A[cl]], 2));
        mp[A[cl]]++;
    }

    while (cr < r) {
        cr++;
        cur_ans += 1LL * A[cr] * (pow(mp[A[cr]] + 1, 2) - pow(mp[A[cr]], 2));
        mp[A[cr]]++;
    }

    while (cl < l) {
        cur_ans += 1LL * A[cl] * (pow(mp[A[cl]] - 1, 2) - pow(mp[A[cl]], 2));
        mp[A[cl]]--;
        cl++;
    }

    while (r < cr) {
        cur_ans += 1LL * A[cr] * (pow(mp[A[cr]] - 1, 2) - pow(mp[A[cr]], 2));
        mp[A[cr]]--;
        cr--;
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> T;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0, a, b; i < T; i++) {
        cin >> a >> b;
        queries.push_back(query(a - 1, b - 1, i));
    }

    sort(queries.begin(), queries.end(), [](query a, query b) {
        if (a.l / bsz != b.l / bsz)
            return a.l / bsz < b.l / bsz;
        return a.r < b.r;
    });

    for (query i : queries) {
        update(i.l, i.r);
        ans[i.idx] = cur_ans;
    }

    for (int i = 0; i < T; i++)
        cout << ans[i] << "\n";
}
