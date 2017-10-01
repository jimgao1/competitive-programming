
#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

int T, N, M, dp[MAXN];
bool cs[MAXN][MAXN];
vector<int> adj1[MAXN];
vector<pair<int, int>> e;

int comps = 0, cnt = 1, id[MAXN], lowlink[MAXN], csize[MAXN];
bool instack[MAXN], visited[MAXN];
stack<int> st;
unordered_map<int, int> dict;

void tarjans(int node) {
//    printf("tarjans: node = %d\n", node);

    id[node] = cnt;
    lowlink[node] = cnt;
    cnt++;

    st.push(node);
    instack[node] = true;

    for (int i : adj1[node]) {
        if (id[i] == 0) {
            tarjans(i);
            lowlink[node] = min(lowlink[node], lowlink[i]);
        } else if (instack[i]) {
            lowlink[node] = min(lowlink[node], id[i]);
        }
    }

    if (lowlink[node] == id[node]) {
        vector<int> curcomp;
        while (true) {
            int c = st.top();
            st.pop();
            instack[c] = false;
            curcomp.push_back(c);

            if (c == node) break;
        }

        for (int i : curcomp) {
            dict[i] = comps;
            visited[i] = true;
        }
        csize[comps] = curcomp.size();
        comps++;
    }
}

void init() {
    comps = 0;
    cnt = 1;
    memset(cs, 0, sizeof cs);
    memset(dp, -1, sizeof dp);
    memset(visited, 0, sizeof visited);
    memset(id, 0, sizeof id);
    memset(lowlink, 0, sizeof lowlink);
    memset(csize, 0, sizeof csize);
    memset(instack, 0, sizeof instack);
    e.clear();
    for (int i = 0; i < MAXN; i++) {
        adj1[i].clear();
    }
    while (!st.empty()) st.pop();
    dict.clear();
}

int dfs(int cur, int pre) {
    //printf("dfs: cur = %d, pre = %d\n", cur, pre);

    //if (dp[cur] != -1) return dp[cur];
    int ans = 0;
    for (int i = 0; i < comps; i++) {
        if (i != pre && cs[cur][i]) {
            ans = max(ans, dfs(i, cur));
        }
    }
    return ans + csize[cur];
}

void solve() {
    init();

    cin >> N >> M;
    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        a--, b--;
        adj1[a].push_back(b);
        e.push_back(make_pair(a, b));
    }

    for (int i = 0; i < N; i++) {
        if (!visited[i])
            tarjans(i);
    }

    for (pair<int, int> i : e) {
        int ra = dict[i.first], rb = dict[i.second];
        if (ra == rb) continue;
        cs[ra][rb] = true;
    }

    int ans = 0;
    for (int i = 0; i < comps; i++) ans = max(ans, dfs(i, -1));

    cout << ans << endl;
}

int main() {
    cin >> T;
    while (T--)
        solve();
}
