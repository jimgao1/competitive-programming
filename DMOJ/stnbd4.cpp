
#include <bits/stdc++.h>

#define MAXN 100005
#define ll long long

using namespace std;

struct query {
    int l, r, idx;
    query(int a, int b, int c) {
        l = a, r = b, idx = c;
    }
};

int N, Q, block_size, cl = 0, cr = 0;
int indices[MAXN];
ll cur_ans = 0, A[MAXN], ans[MAXN];
vector<pair<ll, int>> nums;
vector<query> queries;

ll bit[MAXN];

void bit_add(int idx, ll val) {
    idx++;
    while (idx <= MAXN) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

ll bit_query(int idx) {
    idx++;
    ll a = 0;
    while (idx > 0) {
        a += bit[idx];
        idx -= (idx & -idx);
    }
    return a;
}

void update_mo(int l, int r) {
    // Ensure current left is equal to query left
    while (cl > l) {
        cl--;
        cur_ans += bit_query(indices[cl]);
        bit_add(indices[cl], 1);
    }

    while (cl < l) {
        cur_ans -= bit_query(indices[cl] - 1);
        bit_add(indices[cl], -1);
        cl++;
    }

    // Ensure current right is equal to query right
    while (cr < r) {
        cr++;
        cur_ans += (cr - cl) - bit_query(indices[cr]);
        bit_add(indices[cr], 1);
    }

    while (cr > r) {
        cur_ans -= (cr - cl + 1) - bit_query(indices[cr]);
        bit_add(indices[cr], -1);
        cr--;
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    block_size = sqrt(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        nums.push_back(make_pair(A[i], i));
    }
    sort(nums.begin(), nums.end());

    for (int i = 0; i < N; i++) {
        indices[nums[i].second] = i + 1;
    }

    cin >> Q;
    for (int i = 0, l, r; i < Q; i++) {
        cin >> l >> r;
        queries.push_back(query(l - 1, r - 1, i));
    }
    sort(queries.begin(), queries.end(), [](query a, query b) {
        int block_a = a.l / block_size, block_b = b.l / block_size;
        if (block_a != block_b)
            return block_a < block_b;
        return a.r < b.r;
    });

    bit_add(indices[0], 1);
    for (int i = 0; i < Q; i++) {
        update_mo(queries[i].l, queries[i].r);
        ans[queries[i].idx] = cur_ans;
    }

    for (int i = 0; i < Q; i++) {
        cout << ans[i] << "\n";
    }
}
