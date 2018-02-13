#include <bits/stdc++.h>

#define MAXN 50
#define pii pair<int, int>

using namespace std;

int N, M;
bool visited[MAXN];
unordered_set<int> adjList[MAXN];
vector<pair<int, int>> e;

void dfs(int cur) {
    visited[cur] = 1;
    for (int i : adjList[cur]) {
        if (!visited[i])
            dfs(i);
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        a--, b--;
        adjList[a].insert(b);
        e.push_back(make_pair(a, b));
    }

    for (int i = 0; i < M; i++) {
        memset(visited, 0, sizeof visited);
        adjList[e[i].first].erase(e[i].second);
        dfs(0);
        if (visited[N - 1]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        adjList[e[i].first].insert(e[i].second);
    }
}
