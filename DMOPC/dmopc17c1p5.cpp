
#include <bits/stdc++.h>

#define pii pair<int, int>
#define MAXN 1000006

using namespace std;

struct query {
    int l, r, idx;
    query(int a, int b, int c) {
        l = a, r = b, idx = c;
    }
};

int N, Q, bit[MAXN], A[MAXN], ans[MAXN];
vector<query> queries;
stack<pii > st;

int bit_query(int i) {
    int sum = 0;
    i++;
    while (i > 0) {
        sum += bit[i];
        i -= (i & -i);
    }
    return sum;
}

void update(int i, int val) {
    i++;
    while (i <= MAXN) {
        bit[i] += val;
        i += (i & -i);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0, a, b; i < Q; i++) {
        cin >> a >> b;
        a--, b--;
        queries.push_back(query(a, b, i));
    }
    sort(queries.begin(), queries.end(), [](query a, query b) {
        return a.l > b.l;
    });

    update(N, 1);
    st.push(make_pair(N + 1, N));
    for (int i = N - 1, idx = 0; i >= 0 && idx < Q;) {
        while (!st.empty()) {
            if (st.top().first < A[i]) {
                update(st.top().second, -1);
                st.pop();
            } else {
                break;
            }
        }
        st.push(make_pair(A[i], i));
        update(i, 1);

        while (idx < Q && queries[idx].l == i) {
            int n = bit_query(queries[idx].r);
            ans[queries[idx].idx] = n;
            idx++;
        }

        i--;
    }

    for (int i = 0; i < Q; i++)
        printf("%d\n", ans[i]);
}
