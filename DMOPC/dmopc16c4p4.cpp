
#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

struct query {
    int l, r, idx;
    query(int a, int b, int c) {
        l = a, r = b, idx = c;
    }
};

int N, Q, S, A[MAXN], freq[MAXN], ans[MAXN];
bool seen[MAXN], valid[MAXN];
vector<query> queries;

int l, r, cur_ans = 0;

void update(int idx) {
    printf("update: idx = %d\n", idx);
    if (!seen[idx]) {
        freq[A[idx]]++;
        bool a = valid[A[idx]];
        bool b = valid[A[idx]] = freq[A[idx]] % 2 == 0 && freq[A[idx]] > 0;
        if (!a & b)
            cur_ans++;
        else if (a & !b)
            cur_ans--;
    } else {
        freq[A[idx]]--;
        bool a = valid[A[idx]];
        bool b = valid[A[idx]] = freq[A[idx]] % 2 == 0 && freq[A[idx]] > 0;
        if (!a & b)
            cur_ans++;
        else if (a & !b)
            cur_ans--;
    }

    seen[idx] = !seen[idx];
}

int main() {
//    freopen("/tmp/shit.txt", "r", stdin);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> Q;
    for (int i = 0, a, b; i < Q; i++) {
        cin >> a >> b;
        a--, b--;
        queries.push_back(query(a, b, i));
    }

    S = sqrt(N);
    sort(queries.begin(), queries.end(), [](query a, query b) {
        if (a.l / S != b.l / S)
            return a.l / S < b.l / S;
        return a.r > b.r;
    });

    l = queries[0].l, r = queries[0].l - 1;

    for (query i : queries) {
        while (i.l < l) update(--l);
        while (i.r > r) update(++r);
        while (i.l > l) update(l++);
        while (i.r < r) update(r--);

        ans[i.idx] = cur_ans;
    }

    for (int i = 0; i < Q; i++)
        printf("%d\n", ans[i]);
}
