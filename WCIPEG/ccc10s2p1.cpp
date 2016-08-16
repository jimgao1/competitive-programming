#include <bits/stdc++.h>

#define MAXN 1001
#define INF 0x3f3f3f3f
#define pii pair<int, int>

using namespace std;

int N, M, T, w[MAXN], last[MAXN], cnt[MAXN];
vector<int> adjList[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> w[i];

    cin >> M;
    for (int i = 0, a, b; i < M; i++) {
        cin >> a >> b;
        adjList[a - 1].push_back(b - 1);
    }

    for (int i = 0; i < N; i++) {
        last[i] = -10001;
    }

    cin >> T;

    pq.push({0, 0});
    while (!pq.empty()) {
        int ctime = pq.top().first, id = pq.top().second;
        pq.pop();
        if (ctime > T) continue;
        if (ctime - last[id] <= w[id]) continue;

        last[id] = ctime;
        cnt[id]++;
        for (int i : adjList[id]) {
            pq.push({ctime + w[i], i});
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", cnt[i]);
    }
}
