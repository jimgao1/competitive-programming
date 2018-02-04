
#include <bits/stdc++.h>

#define pii pair<int, int>
#define MAXN 50001
#define LOGMAXN 16

using namespace std;

int N, K;
int pa[MAXN][LOGMAXN];
int depth[MAXN], dist[MAXN];
vector<pii > adj[MAXN];

void dfs(int cur, int d, int prev) {
    depth[cur] = d;
    pa[cur][0] = prev;
    for (pii i : adj[cur]) {
        if (i.first != prev) {
            dist[i.first] = dist[cur] + i.second;
            dfs(i.first, d + 1, cur);
        }
    }
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

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0, a, b, w; i < N - 1; i++) {
        cin >> a >> b >> w;
        adj[a].push_back(make_pair(b, w));
        adj[b].push_back(make_pair(a, w));
    }

    build();

    cin >> K;
    for (int i = 0, a, b; i < K; i++) {
        cin >> a >> b;
        int l = lca(a, b);

        cout << dist[a] + dist[b] - 2 * dist[l] << "\n";
    }
}

