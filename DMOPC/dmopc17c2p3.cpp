#include <bits/stdc++.h>

#define MAXN 200001

using namespace std;

int N, R, X, Y, ans = 1e9;
int dist[MAXN];
bool bunny[MAXN], need[MAXN], path[MAXN];
vector<int> adjList[MAXN];

void mark(int cur, int pre) {
    if (cur == Y) path[cur] = true;
    need[cur] |= bunny[cur];
    for (int i : adjList[cur]) {
        if (i != pre) {
            mark(i, cur);
            need[cur] |= need[i];
            path[cur] |= path[i];
        }
    }
}

int dfs(int cur, int pre) {
    if (bunny[cur]) dist[cur] = 0;
    for (int i : adjList[cur]){
        if (i == pre) continue;

        dfs(i, cur);
        dist[cur] = min(dist[cur], dist[i] + 1);
    }

    if (path[cur]) ans = min(ans, dist[cur]);
}

int main() {
    cin >> N >> R;
    for (int i = 0, a, b; i < N - 1; i++) {
        cin >> a >> b;
        a--, b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    for (int i = 0, b; i < R; i++) {
        cin >> b;
        bunny[b - 1] = true;
    }
    cin >> X >> Y;
    X--, Y--;

    mark(X, -1);
    memset(dist, 0x3f, sizeof dist);

    dfs(X, -1);
    cout << ans << endl;
}
