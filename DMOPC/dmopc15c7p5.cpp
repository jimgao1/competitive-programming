
#include <bits/stdc++.h>

#define MAXN 100005
#define ll long long

using namespace std;

int N, Q;
ll segtree[MAXN * 4];
ll idx = 0, depth[MAXN * 4], H[MAXN * 4], E[MAXN * 4], L[MAXN * 4];
vector<int> adjList[MAXN];
set<ll> occ[MAXN];

/*
	H[i]	minimum DFS number for node i
	E[i]	the i'th visited node, euler tour
	L[i]	depth of node i
*/
void dfs(int cur, int dep, int pre){
    depth[cur] = dep;
    occ[cur].insert(idx);
    H[cur] = min(H[cur], idx);
    E[idx] = cur;
    L[idx] = dep;
    idx++;

    for (int i : adjList[cur]){
        if (i == pre) continue;
        dfs(i, dep + 1, cur);

        occ[cur].insert(idx);
        E[idx] = cur;
        L[idx] = dep;
        idx++;
    }
}

// Build segment tree, stores index of node with least depth
// in a range.
void build(int node, int l, int r){
    if (l == r){
        segtree[node] = l;
        return;
    }

    int mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);

    if (L[segtree[node * 2]] < L[segtree[node * 2 + 1]]){
        segtree[node] = segtree[node * 2];
    } else {
        segtree[node] = segtree[node * 2 + 1];
    }
}

int query(int node, int l, int r, int ql, int qr){
    if (ql > r || qr < l) return -1;
    if (l >= ql && r <= qr) return segtree[node];

    int mid = (l + r) / 2;
    ll p1 = query(node * 2, l, mid, ql, qr);
    ll p2 = query(node * 2 + 1, mid + 1, r, ql, qr);

    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    if (L[p1] < L[p2]) return p1;
    return p2;
}

// Finding LCA of nodes a and b using segment tree
int find_lca(int a, int b){
    if (H[a] > H[b]) swap(a, b);
    return E[query(1, 0, idx - 1, H[a], H[b])];
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0, a; i < N; i++){
        cin >> a;
        for (int j = 0, b; j < a; j++){
            cin >> b;
            adjList[i].push_back(b - 1);
        }
    }

    memset(H, 0x3f, sizeof H);
    memset(L, 0x3f, sizeof L);
    dfs(0, 0, -1);
    build(1, 0, idx - 1);

    cin >> Q;
    for (int i = 0, a, b; i < Q; i++){
        cin >> a >> b;
        a--, b--;

        int lca = find_lca(a, b);
        if (H[a] <= H[b]){
            cout << H[b] - H[lca] - (depth[a] - depth[lca]) << "\n";
        } else {
            set<ll>::iterator it = occ[lca].lower_bound(H[a]);

            ll sum;
            if (*it == H[a]){
                // If the node is a leaf node
                sum = 0;
            } else {
                sum = *it;
                it --;
                sum -= *it;
            }

            cout << H[b] - H[lca] - (depth[a] - depth[lca]) + sum << "\n";
        }
    }
}

