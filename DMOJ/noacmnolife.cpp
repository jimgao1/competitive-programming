#include <bits/stdc++.h>

#define MAXN 301

using namespace std;

int T, N, K, label[MAXN], cnt[MAXN], dist[MAXN][MAXN];
long double choose[MAXN][MAXN];
vector<int> adjList[MAXN];
unordered_set<int> used;

void precompute() {
    choose[0][0] = 1;
    for (int i = 1; i < MAXN; i++) {
        choose[i][0] = choose[i][i] = 1;
        for (int j = 1; j < i; j++) {
            choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
        }
    }
}

void init() {
    memset(cnt, 0, sizeof cnt);
    memset(dist, 0x3f, sizeof dist);
    for (int i = 0; i < MAXN; i++) {
        adjList[i].clear();
        dist[i][i] = 0;
    }
}

void dfs(int cur, int pre) {
    bool exists = false;
    if (used.count(label[cur])) exists = true;
    used.insert(label[cur]);
    cnt[cur] = used.size();

    for (int i : adjList[cur]) {
        if (i == pre) continue;
        dfs(i, cur);
    }
    if (!exists) used.erase(used.find(label[cur]));
}

void solve() {
    cin >> N >> K;
    for (int i = 0, a, b; i < N - 1; i++) {
        cin >> a >> b;
        a--, b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
        dist[a][b] = dist[b][a] = 1;
    }
    for (int i = 0; i < N; i++) cin >> label[i];

    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    long double num = 0;

    for (int a = 0; a < N; a++) {
        used.clear();
        dfs(a, -1);

        for (int b = a + 1; b < N; b++) {
            int total = 0;
            for (int i = 0; i < N; i++) {
                if (dist[a][i] > dist[a][b] || dist[b][i] > dist[a][b]) continue;
                if (dist[a][i] == dist[a][b] && i < b) continue;
                if (dist[b][i] == dist[a][b] && i < a) continue;
                total++;
            }

            if (total < 2) continue;

            long double val = (long double) cnt[b] * choose[total - 2][K - 2];
            num += val;
        }
    }

    num /= choose[N][K];

    cout << setprecision(10) << num << "\n";
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    precompute();

    cin >> T;
    while (T--) {
        init();
        solve();
    }
}
