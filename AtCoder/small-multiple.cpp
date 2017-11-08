
#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

int K, dist[MAXN];
queue<pair<int, int>> q;

int main() {
    cin >> K;
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    q.push(make_pair(1, 0));
    while (!q.empty()) {
        int cur, cost;
        tie(cur, cost) = q.front();
        q.pop();

        int n1 = (cur * 10) % K, n2 = (cur + 1) % K;
        if (n1 < MAXN) {
            if (dist[n1] > cost) {
                dist[n1] = cost;
                q.push(make_pair(n1, cost));
            }
        }

        if (n2 < MAXN) {
            if (dist[n2] > cost + 1) {
                dist[n2] = cost + 1;
                q.push(make_pair(n2, cost + 1));
            }
        }
    }

    cout << dist[0] + 1 << endl;
}
