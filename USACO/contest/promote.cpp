
#include <bits/stdc++.h>

#define pii pair<int, int>
#define MAXN 100005

using namespace std;

int idx = 0, N, R[MAXN], bit[MAXN];
int vis[MAXN], tsize[MAXN], ans[MAXN];
vector<pii > nodes;
vector<int> adjList[MAXN];

void update(int i, int val) {
    i += 2;
    for (; i <= MAXN; i += (i & -i))
        bit[i] += val;
}

int query(int i) {
    i += 2;

    int ans = 0;
    for (; i > 0; i -= (i & -i))
        ans += bit[i];
    return ans;
}

void dfs(int cur) {
    vis[cur] = idx++;
    tsize[cur] = 1;

    for (int i : adjList[cur]) {
        dfs(i);
        tsize[cur] += tsize[i];
    }
}

int main() {
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> R[i];
        nodes.push_back(make_pair(i, R[i]));
    }
    for (int i = 1, x; i < N; i++) {
        cin >> x;
        adjList[x - 1].push_back(i);
    }

    sort(nodes.begin(), nodes.end(), [](pii a, pii b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first > b.first;
    });

    dfs(0);

    for (pii i : nodes) {
        // For each node, ranked by decreasing rating, find out how many, of that subtree
        // has already been visited

        int l = vis[i.first];
        int r = vis[i.first] + tsize[i.first] - 1;
        ans[i.first] = query(r) - query(l - 1);

        // Update the current node
        update(vis[i.first], 1);
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", ans[i]);
    }
}
