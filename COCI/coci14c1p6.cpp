
#include <bits/stdc++.h>

#define MAXN 500005
#define ll long long

using namespace std;

int N, K;
int L[MAXN], lid[MAXN], near[MAXN];
ll S = 0, long1[MAXN], long2[MAXN], dist[MAXN];
bool needed[MAXN];
vector<pair<int, ll>> adjList[MAXN];

inline ll max(int a, ll b) { return a > b ? a : b; }

void mark(int cur, int pre) {
    for (pair<int, ll> i : adjList[cur]) {
        if (i.first == pre) continue;
        mark(i.first, cur);
        if (needed[i.first]) {
            S += i.second;
            needed[cur] = true;
        }
    }
}

// Calculates top-2 maximum branches
void calc1(int cur, int pre) {
    for (pair<int, ll> i : adjList[cur]) {
        if (i.first == pre || !needed[i.first]) continue;
        calc1(i.first, cur);

        if (long1[i.first] + i.second > long1[cur]) {
            long2[cur] = long1[cur];
            long1[cur] = long1[i.first] + i.second;
            lid[cur] = i.first;
        } else if (long1[i.first] + i.second > long2[cur]) {
            long2[cur] = long1[i.first] + i.second;
        }
    }
}

// Calculates longest path for each node
void calc2(int cur, int pre) {
    for (pair<int, ll> i : adjList[cur]) {
        if (i.first == pre || !needed[i.first]) continue;

        if (i.first == lid[cur]) {
            L[i.first] = max(L[cur], long2[cur]) + i.second;
        } else {
            L[i.first] = max(L[cur], long1[cur]) + i.second;
        }

        calc2(i.first, cur);
    }
    L[cur] = max(L[cur], long1[cur]);
}

// Calculate distance of each node to 0
void calc3(int cur, int pre) {
    if (needed[cur]) dist[cur] = 0, near[cur] = cur;
    for (pair<int, ll> i : adjList[cur]) {
        if (i.first == pre) continue;
        dist[i.first] = dist[cur] + i.second;
        near[i.first] = near[cur];
        calc3(i.first, cur);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0, a, b, c; i < N - 1; i++) {
        cin >> a >> b >> c;
        a--, b--;
        adjList[a].push_back(make_pair(b, c));
        adjList[b].push_back(make_pair(a, c));
    }
    int tmp;
    for (int i = 0, x; i < K; i++) {
        cin >> x;
        tmp = x - 1;
        needed[x - 1] = true;
    }

    mark(tmp, -1);
    calc1(tmp, -1);
    calc2(tmp, -1);
    calc3(tmp, -1);

    for (int i = 0; i < N; i++) {
        cout << dist[i] + 2 * S - L[near[i]] << "\n";
    }
}

