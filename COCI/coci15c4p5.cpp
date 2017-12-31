
#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

struct edge {
    int a, b, w;
    edge(int x, int y, int z) {
        a = x, b = y, w = z;
    }
};

int N, xval[MAXN], dset[MAXN], dsize[MAXN], order[MAXN];
vector<edge> e;
vector<int> mem[MAXN];
vector<pair<int, int>> adjList[MAXN];

long long ans = 0, result[MAXN];
unordered_map<int, int> freq[MAXN];

void dfs(int cur, int pre, int val) {
    xval[cur] = val;
    for (pair<int, int> i : adjList[cur]) {
        if (i.first != pre) {
            dfs(i.first, cur, val ^ i.second);
        }
    }
}

void uinit() {
    for (int i = 0; i < N; i++) {
        dset[i] = i, dsize[i] = 1;
        freq[i][xval[i]] = 1;
        mem[i].push_back(i);
    }
}

int ufind(int n) {
    while (n != dset[n]) n = dset[n];
    return n;
}

void mergeSet(int a, int b) {
    int ra = ufind(a), rb = ufind(b);
    if (ra == rb) return;

    if (mem[ra].size() > mem[rb].size()) swap(ra, rb);

    for (int i : mem[ra]) {
        ans += (long long) freq[rb][xval[i]];
    }

    for (int i : mem[ra]) {
        freq[rb][xval[i]]++;
        dset[i] = rb;
        mem[rb].push_back(i);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0, a, b, w; i < N - 1; i++) {
        cin >> a >> b >> w;
        a--, b--;
        e.push_back(edge(a, b, w));
        adjList[a].push_back(make_pair(b, w));
        adjList[b].push_back(make_pair(a, w));
    }

    dfs(0, -1, 0);
    for (int i = 0; i < N - 1; i++) {
        cin >> order[i];
        order[i]--;
    }

    uinit();

    for (int i = N - 2; i >= 0; i--) {
        int a = e[order[i]].a, b = e[order[i]].b;
        mergeSet(a, b);
        result[i] = ans;
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << "\n";
    }
}

