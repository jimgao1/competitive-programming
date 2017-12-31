
#include <bits/stdc++.h>

#define MAXN 200001

using namespace std;

struct q {
    bool update;
    int a, b, idx, sorted_idx;
    q(int aa, int bb, int i, int si) {
        update = false;
        a = aa, b = bb;
        idx = i, sorted_idx = si;
    }
};

int N, segtree[MAXN * 4];

int qval[MAXN], qidx[MAXN];
bool update[MAXN];
vector<q> queries;

int push_up(int idx) {
    if (segtree[idx * 2] == -1) return segtree[idx * 2 + 1];
    if (segtree[idx * 2 + 1] == -1) return segtree[idx * 2];

    if (queries[segtree[idx * 2]].a > queries[segtree[idx * 2 + 1]].a)
        return segtree[idx * 2];
    return segtree[idx * 2 + 1];
}

void insert(int idx, int left, int right, int node) {
    if (left == right) {
        segtree[idx] = node;
        return;
    }

    int mid = (left + right) / 2;
    if (mid >= queries[node].sorted_idx)
        insert(idx * 2, left, mid, node);
    else
        insert(idx * 2 + 1, mid + 1, right, node);

    segtree[idx] = push_up(idx);
}

int query(int idx, int left, int right, int node) {
    if (right <= queries[node].sorted_idx) return -1;
    if (segtree[idx] == -1) return -1;
    if (queries[segtree[idx]].a < queries[node].a) return -1;

    if (left == right) return segtree[idx];

    int mid = (left + right) / 2;
    int tmp = query(idx * 2, left, mid, node);
    if (tmp != -1) return tmp;

    return query(idx * 2 + 1, mid + 1, right, node);
}

int main() {
    cin >> N;
    for (int i = 0, curIndex = 0; i < N; i++) {
        string cmd;
        int a, b;

        cin >> cmd;
        if (cmd == "D") {
            cin >> a >> b;
            queries.push_back(q(a, b, curIndex, curIndex));
            qidx[i] = curIndex;
            ++curIndex;
            update[i] = true;
        } else {
            cin >> a;
            qidx[i] = a - 1;
        }
    }

    sort(queries.begin(), queries.end(), [](q a, q b) {
        if (a.b != b.b) return a.b < b.b;
        return a.a < b.a;
    });

    for (int i = 0; i < queries.size(); i++) {
        queries[i].sorted_idx = i;
    }

    sort(queries.begin(), queries.end(), [](q a, q b){
        return a.idx < b.idx;
    });

    memset(segtree, -1, sizeof segtree);
    for (int i = 0; i < N; i++) {
        if (update[i]) {
            insert(1, 0, N - 1, qidx[i]);
        } else {
            int tmp = query(1, 0, N - 1, qidx[i]);
            if (tmp != -1)
                printf("%d\n", tmp + 1);
            else
                printf("NE\n");
        }
    }
}
