
#include <bits/stdc++.h>

#define MAXN 200005

using namespace std;

int N, D, A[MAXN], B[MAXN], dist[MAXN];

struct cmp1 {
    bool operator()(int i, int j) {
        return A[i] > A[j];
    }
};

struct cmp2 {
    bool operator()(int i, int j) {
        return B[i] > B[j];
    }
};

multiset<int, cmp1> mp1;
multiset<int, cmp2> mp2;
queue<int> q;

int main() {
    freopen("piepie.in", "r", stdin);
    freopen("piepie.out", "w", stdout);

    memset(dist, -1, sizeof dist);

    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        if (B[i] == 0) {
            dist[i] = 1;
            q.push(i);
        } else {
            mp2.insert(i);
        }
    }

    for (int i = N; i < N * 2; i++) {
        cin >> A[i] >> B[i];
        if (A[i] == 0) {
            dist[i] = 1;
            q.push(i);
        } else {
            mp1.insert(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur < N) {
            while (true) {
                multiset<int>::iterator it = mp1.lower_bound(cur);
                if (it == mp1.end() || A[*it] < A[cur] - D) break;
                dist[*it] = dist[cur] + 1;
                q.push(*it);
                mp1.erase(it);
            }
        } else {
            while (true) {
                multiset<int>::iterator it = mp2.lower_bound(cur);
                if (it == mp2.end() || B[*it] < B[cur] - D) break;
                dist[*it] = dist[cur] + 1;
                q.push(*it);
                mp2.erase(it);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", dist[i]);
    }
}
