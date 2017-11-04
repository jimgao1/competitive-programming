// oh boi

#include <bits/stdc++.h>

#define MAXN 30005
#define pii pair<int, int>

using namespace std;

int N, M, B[MAXN], P[MAXN], dist[MAXN], st, ed;
unordered_set<int> power[MAXN];
priority_queue<pii, vector<pii >, greater<pii>> pq;

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> B[i] >> P[i];
        power[B[i]].insert(P[i]);
    }

    st = B[0], ed = B[1];
    memset(dist, 0x3f, sizeof dist);

    pq.push(make_pair(0, st));
    while (!pq.empty()) {
        int cur, cost;
        tie(cost, cur) = pq.top(); // owo
        pq.pop();

        if (cur == ed) {
            printf("%d\n", cost);
            return 0;
        }

        for (int pp : power[cur]) {
            for (int k = 1; cur + pp * k <= N; k++) {
                int dst = cur + pp * k;
                if (dist[dst] > cost + k){
                    dist[dst] = cost + k;
                    pq.push(make_pair(dist[dst], dst));
                }

                if (power[dst].count(pp)) break;
            }

            for (int k = 1; cur - pp * k >= 0; k++) {
                int dst = cur - pp * k;
                if (dist[dst] > cost + k){
                    dist[dst] = cost + k;
                    pq.push(make_pair(dist[dst], dst));
                }

                if (power[dst].count(pp)) break;
            }
        }
    }

    printf("-1\n");
}
