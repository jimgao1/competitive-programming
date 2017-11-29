
#include <bits/stdc++.h>
#include <bits/extc++.h>

#define MAXN 100005
#define ll long long

using namespace std;
using namespace __gnu_pbds;

int N;
ll M, ans = 0, C[MAXN], L[MAXN], sum[MAXN];
vector<int> adjList[MAXN];
__gnu_pbds::priority_queue<int, less<int>, pairing_heap_tag> pq[MAXN];

void dfs(int cur) {
    sum[cur] = C[cur];
    pq[cur].push(C[cur]);

    for (int i : adjList[cur]) {
        dfs(i);

        pq[cur].join(pq[i]);
        sum[cur] += sum[i];
    }

    while (sum[cur] > M) {
        ll val = pq[cur].top();
        sum[cur] -= val;
        pq[cur].pop();
    }

    ans = max(ans, (ll)(L[cur] * pq[cur].size()));
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0, x; i < N; i++) {
        cin >> x >> C[i] >> L[i];
        if (i != 0) adjList[x - 1].push_back(i);
    }

    dfs(0);

    cout << ans << "\n";
}
