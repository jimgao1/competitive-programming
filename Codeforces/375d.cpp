
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

#define MAXN 100010

using namespace std;

struct query {
    int l, r, x, idx;
    query(){}
    query(int a, int b, int c, int d) {
        l = a, r = b, x = c, idx = d;
    }
};

int N, M, S, C[MAXN], A[MAXN], sz[MAXN], bit[MAXN], ans[MAXN], mp[MAXN];
bool seen[MAXN];
query queries[MAXN];
vector<int> order, adjList[MAXN];

void dfs(int cur, int pre) {
    A[cur] = order.size();
    sz[cur] = 1;
    order.push_back(cur);
    for (int i : adjList[cur]) {
        if (i != pre) {
            dfs(i, cur);
            sz[cur] += sz[i];
        }
    }
}

void add(int i, int val) {
    i += 2;
    while (i <= MAXN) {
        bit[i] += val;
        i += (i & -i);
    }
}

int sum(int i) {
    i += 2;
    int ans = 0;
    while (i > 0) {
        ans += bit[i];
        i -= (i & -i);
    }
    return ans;
}

void process(int node) {
    if (!seen[node]) {
        int cnt = mp[C[node]]++;
        add(cnt, -1);
        add(cnt + 1, 1);
    } else {
        int cnt = mp[C[node]]--;
        add(cnt, -1);
        add(cnt - 1, 1);
    }

    seen[node] = !seen[node];
}

int cl, cr;
void update_mo(query& q) {
    while (q.l < cl) process(order[--cl]);
    while (q.r > cr) process(order[++cr]);

    while (q.l > cl) process(order[cl++]);
    while (q.r < cr) process(order[cr--]);

    ans[q.idx] = sum(MAXN - 5) - sum(q.x - 1);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    for (int i = 0, a, b; i < N - 1; i++) {
        cin >> a >> b;
        a--, b--;
        adjList[a].emplace_back(b);
        adjList[b].emplace_back(a);
    }

    dfs(0, -1);

    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        a--;
        queries[i] = query(A[a], A[a] + sz[a] - 1, b, i);
    }

    S = sqrt(N);

    sort(queries, queries + M, [](query a, query b) {
        if (a.l / S != b.l / S) return a.l / S < b.l / S;
        return a.r < b.r;
    });

    cl = queries[0].l, cr = queries[0].l - 1;
    for (int i = 0; i < M; i++) update_mo(queries[i]);

    for (int i = 0; i < M; i++) {
        printf("%d\n", ans[i]);
    }
}
