
#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

int N, cnt[MAXN], state[MAXN];
bool deg[MAXN];
vector<int> adjList[MAXN];
pair<int, int> ans[MAXN];

void dfs(int cur) {
    cnt[cur] = 1;
    if (adjList[cur].size() == 0) {
        if (state[cur] == 0) {
            ans[cur].first = 0;
            ans[cur].second = 1;
        } else if (state[cur] == 1) {
            ans[cur].first = 0;
            ans[cur].second = 0;
        } else {
            ans[cur].first = 1;
            ans[cur].second = 1;
        }
    } else if (state[cur] == 0) {
        pair<int, int> a, b;
        b.first = b.second = 1;
        for (int i : adjList[cur]){
            dfs(i);
            cnt[cur] += cnt[i];
            a.first += ans[i].first;
            a.second += ans[i].second;
            b.first += (cnt[i] - ans[i].second);
            b.second += (cnt[i] - ans[i].first);
        }

        ans[cur].first = min(a.first, b.first);
        ans[cur].second = max(a.second, b.second);
    } else if (state[cur] == 1) {
        for (int i : adjList[cur]) {
            dfs(i);
            cnt[cur] += cnt[i];
            ans[cur].first += ans[i].first;
            ans[cur].second += ans[i].second;
        }
    } else {
        ans[cur].first = 1;
        ans[cur].second = 1;
        for (int i : adjList[cur]) {
            dfs(i);
            cnt[cur] += cnt[i];
            ans[cur].first += (cnt[i] - ans[i].second);
            ans[cur].second += (cnt[i] - ans[i].first);
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        string a, b;
        int c;
        cin >> a;
        if (a == "C") {
            cin >> b;
            state[i] = (b == "?" ? 0 : (b == "AC" ? 1 : 2));
        } else {
            cin >> c >> b;
            deg[i] = 1;
            state[i] = (b == "?" ? 0 : (b == "AC" ? 1 : 2));
            adjList[c].push_back(i);
        }
    }

    state[0] = 1;
    for (int i = 1; i <= N; i++) {
        if (!deg[i]) adjList[0].push_back(i);
    }

    dfs(0);
    printf("%d %d\n", ans[0].first, ans[0].second);
}
