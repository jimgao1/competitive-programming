/*
 ID: jim.yub1
 LANG: C++11
 TASK: schlnet
 */

#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int N, in[MAXN], out[MAXN];
bool sccadj[MAXN][MAXN];
vector<int> adj[MAXN];

int cnt = 1, sccid = 0, id[MAXN], lowlink[MAXN], scc[MAXN];
bool instack[MAXN];
stack<int> st;

void tarjans(int node) {

    id[node] = cnt;
    lowlink[node] = cnt;
    cnt++;

    st.push(node);
    instack[node] = true;

    for (int i : adj[node]) {
        if (id[i] == 0) {
            tarjans(i);
            lowlink[node] = min(lowlink[node], lowlink[i]);
        } else if (instack[i]) {
            lowlink[node] = min(lowlink[node], id[i]);
        }
    }

    if (lowlink[node] == id[node]) {
        while (true) {
            int c = st.top();
            st.pop();
            instack[c] = false;
            scc[c] = sccid;

            if (c == node) break;
        }

        sccid++;
    }
}

int main() {
    freopen("schlnet.in", "r", stdin);
    freopen("schlnet.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int x;;) {
            cin >> x;
            if (x == 0) break;
            adj[i].push_back(x - 1);
        }
    }

    for (int i = 0; i < N; i++) {
        if (id[i] == 0) tarjans(i);
    }

    for (int i = 0; i < N; i++) {
        for (int j : adj[i]) {
            if (scc[i] == scc[j]) continue;
            sccadj[scc[i]][scc[j]] = true;
        }
    }

    for (int i = 0; i < sccid; i++) {
        for (int j = 0; j < sccid; j++) {
            if (sccadj[i][j])
                in[j]++, out[i]++;
        }
    }

    int a = 0, b = 0;
    for (int i = 0; i < sccid; i++) {
        if (in[i] == 0) a++;
        if (out[i] == 0) b++;
    }

    cout << max(1, a) << endl;
    if (sccid == 1)
        cout << 0 << endl;
    else
        cout << max(a, b) << endl;

}
