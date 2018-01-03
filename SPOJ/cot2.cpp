
#include <bits/stdc++.h>

#define MAXN 40004
#define LOGMAXN 16

#define ll long long

using namespace std;

struct query {
    int l, r, idx;
    int lc;
    query(int a, int b, int c, int d) {
        l = a, r = b, idx = c;
        lc = d;
        if (r < l) swap(l, r);
    }
};

int N, M, S, A[MAXN], B[MAXN], ans[100005];
ll W[MAXN];
vector<int> adjList[MAXN], order;
vector<query> queries;

int curIndex = 0, pa[MAXN][LOGMAXN], depth[MAXN];
bool visited[MAXN];
int curLeft, curRight, curAns = 0;
unordered_map<ll, int> mp;

void init() {
    curIndex = 0;

    memset(A, 0, sizeof A);
    memset(B, 0, sizeof B);
    memset(ans, 0, sizeof ans);
    memset(W, 0, sizeof W);

    memset(pa, 0, sizeof pa);
    memset(depth, 0, sizeof depth);
    memset(visited, 0, sizeof visited);

    order.clear();
    queries.clear();
    mp.clear();

    for (int i = 0; i < MAXN; i++) adjList[i].clear();
}

void dfs(int cur, int d, int prev) {
    depth[cur] = d;
    pa[cur][0] = prev;

    A[cur] = curIndex++;
    order.push_back(cur);

    for (int e : adjList[cur]) {
        if (e != prev)
            dfs(e, d + 1, cur);
    }

    B[cur] = curIndex++;
    order.push_back(cur);
}

void build() {
    dfs(0, 0, -1);
    for (int i = 1; i < LOGMAXN; i++) {
        for (int j = 0; j < N; j++) {
            if (pa[j][i - 1] != -1)
                pa[j][i] = pa[pa[j][i - 1]][i - 1];
        }
    }
}

int lca(int i, int j) {
    if (depth[i] < depth[j])
        swap(i, j);

    for (int k = LOGMAXN - 1; k >= 0; k--) {
        if (pa[i][k] != -1 && depth[pa[i][k]] >= depth[j])
            i = pa[i][k];
    }

    if (i == j)
        return i;

    for (int k = LOGMAXN - 1; k >= 0; k--) {
        if (pa[i][k] != -1 && pa[j][k] != -1 && pa[i][k] != pa[j][k]) {
            i = pa[i][k];
            j = pa[j][k];
        }
    }

    return pa[i][0];
}

void check(int node) {
    if (visited[node] && (--mp[W[node]] == 0)) {
        curAns--;
    } else if (!visited[node] && (mp[W[node]]++ == 0)) {
        curAns++;
    }
    visited[node] = !visited[node];
}

void solve(){
    for (int i = 0; i < N; i++) cin >> W[i];
    for (int i = 0, a, b; i < N - 1; i++) {
        cin >> a >> b;
        a--, b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    build();
    S = sqrt(order.size());

    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        a--, b--;

        if (A[a] > A[b]) swap(a, b);
        int l = lca(a, b);

        if (a == l) {
            queries.push_back(query(A[a], A[b], i, -1));
        } else {
            queries.push_back(query(B[a], A[b], i, l));
        }
    }

    sort(queries.begin(), queries.end(), [](query a, query b) {
        if (a.l / S != b.l / S) return (a.l / S) < (b.l / S);
        return a.r > b.r;
    });

    curLeft = queries[0].l, curRight = queries[0].l - 1, curAns = 0;

    for (query i : queries) {
        while (curRight < i.r) check(order[++curRight]);
        while (curLeft > i.l) check(order[--curLeft]);
        while (curRight > i.r) check(order[curRight--]);
        while (curLeft < i.l) check(order[curLeft++]);

        if (i.lc != -1) check(i.lc);

        ans[i.idx] = curAns;

        if (i.lc != -1) check(i.lc);
    }

    for (int i = 0; i < M; i++) {
        printf("%d\n", ans[i]);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    while(cin >> N >> M){
        init();
        solve();
    }
}
