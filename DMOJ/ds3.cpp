#include <bits/stdc++.h>

#define MAXN 100001
#define INF 0x3f3f3f3f
#define endl "\n"

using namespace std;

struct node {
    int left, right, val, gcd, freq;
};

int N, Q, num[MAXN];
node segtree[MAXN * 3];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void push_up(int id) {
    segtree[id].val = min(segtree[id * 2].val, segtree[id * 2 + 1].val);
    segtree[id].gcd = gcd(segtree[id * 2].gcd, segtree[id * 2 + 1].gcd);

    segtree[id].freq = 0;

    if (segtree[id].gcd == segtree[id * 2].gcd)
        segtree[id].freq += segtree[id * 2].freq;
    if (segtree[id].gcd == segtree[id * 2 + 1].gcd)
        segtree[id].freq += segtree[id * 2 + 1].freq;
}

void build(int id, int left, int right) {
    segtree[id].left = left, segtree[id].right = right;

    if (left == right) {
        segtree[id].val = num[left];
        segtree[id].gcd = num[left];
        segtree[id].freq = 1;

        return;
    }

    int mid = (left + right) / 2;
    build(id * 2, left, mid);
    build(id * 2 + 1, mid + 1, right);

    push_up(id);
}

void update(int id, int uid, int val) {
    int left = segtree[id].left, right = segtree[id].right;

    if (left == right) {
        segtree[id].val = val;
        segtree[id].gcd = val;
        segtree[id].freq = 1;
        return;
    }


    int mid = (left + right) / 2;

    if (uid <= mid) {
        update(id * 2, uid, val);
    } else {
        update(id * 2 + 1, uid, val);
    }

    push_up(id);
}

int queryMin(int id, int qleft, int qright) {
    int left = segtree[id].left, right = segtree[id].right;
    int mid = (left + right) / 2;

    if (qleft <= left && qright >= right) return segtree[id].val;
    if (qright <= mid) return queryMin(id * 2, qleft, qright);
    if (qleft > mid) return queryMin(id * 2 + 1, qleft, qright);

    return min(queryMin(id * 2, qleft, mid),
               queryMin(id * 2 + 1, mid + 1, qright));
}

int queryGCD(int id, int qleft, int qright) {
    int left = segtree[id].left, right = segtree[id].right;
    int mid = (left + right) / 2;

    if (left == qleft && right == qright) return segtree[id].gcd;
    if (qright <= mid) return queryGCD(id * 2, qleft, qright);
    if (qleft > mid) return queryGCD(id * 2 + 1, qleft, qright);

    return gcd(queryGCD(id * 2, qleft, mid),
               queryGCD(id * 2 + 1, mid + 1, qright));
}

int queryCnt(int id, int qleft, int qright, int val) {
    int left = segtree[id].left, right = segtree[id].right;

    if (left == qleft && right == qright)
        return segtree[id].gcd == val ? segtree[id].freq : 0;

    int mid = (left + right) / 2;
    if (qright <= mid) return queryCnt(id * 2, qleft, qright, val);
    if (qleft > mid) return queryCnt(id * 2 + 1, qleft, qright, val);

    return queryCnt(id * 2, qleft, mid, val) +
           queryCnt(id * 2 + 1, mid + 1, qright, val);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (int i = 1; i <= N; i++) cin >> num[i];

    build(1, 1, N);

    for (int i = 0; i < Q; i++) {
        string cmd;
        int a, b;
        cin >> cmd >> a >> b;

        if (cmd == "C") {
            update(1, a, b);
        } else if (cmd == "M") {
            cout << queryMin(1, a, b) << endl;
        } else if (cmd == "G") {
            cout << queryGCD(1, a, b) << endl;
        } else if (cmd == "Q") {
            int val = queryGCD(1, a, b);
            cout << queryCnt(1, a, b, val) << endl;
        }
    }
}
