
#include <bits/stdc++.h>

#define ll long long
#define MAXN 5001

using namespace std;

struct event {
    int src, tar, ts;
    bool add;

    event(int a, int b, int c, bool d) {
        src = a, tar = b, ts = c, add = d;
    }
};

int N, M, K, S, T, A[MAXN], B[MAXN], C[MAXN], D[MAXN];
bool visited[MAXN];
vector<event> e;
queue<int> q;
unordered_set<int> adj[1001];

bool test() {
    while (!q.empty()) q.pop();
    memset(visited, 0, sizeof visited);
    q.push(S);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == T) return 1;
        for (int i : adj[cur]) {
            if (!visited[i]) {
                visited[i] = 1;
                q.push(i);
            }
        }
    }
    return false;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K >> S >> T;
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
        A[i]--, B[i]--;
    }

    S--, T--;

    for (int i = 0; i < M; i++) {
        e.push_back(event(A[i], B[i], C[i], 1));
        e.push_back(event(A[i], B[i], D[i] + 1, 0));
    }

    sort(e.begin(), e.end(), [](event a, event b) {
        if (a.ts == b.ts) return a.src < b.src;
        return a.ts < b.ts;
    });

    e.push_back(event(0, 0, K, 1));

    ll ans = 0;
    for (int i = 0; i < e.size() - 1; i++) {
        if (e[i].add) {
            adj[e[i].src].insert(e[i].tar);
        } else {
            adj[e[i].src].erase(e[i].tar);
        }

        if (test()) {
            ans += e[i + 1].ts - e[i].ts;
        }
    }

    cout << ans << "\n";
}
