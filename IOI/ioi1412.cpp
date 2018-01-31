// Reference: https://pastebin.com/VG1PLdv8
// http://codeforces.com/blog/entry/13442

#include <bits/stdc++.h>

#define MAXN 2000006

using namespace std;

struct {
    int up = 0, down = 1e9;
} segtree[MAXN * 3];

int N, K;
int ans[MAXN];

void combine(int id, int up, int down) {
    segtree[id].up = max(segtree[id].up, up);
    segtree[id].up = min(segtree[id].up, down);
    segtree[id].down = min(segtree[id].down, down);
    segtree[id].down = max(segtree[id].down, up);
}

void update(int id, int cl, int cr, int type, int ql, int qr, int val) {
    if (cl > qr || cr < ql) return;
    if (ql <= cl && qr >= cr) {
        if (type == 1) {
            segtree[id].down = max(segtree[id].down, val);
            segtree[id].up = max(segtree[id].up, val);
        } else {
            segtree[id].down = min(segtree[id].down, val);
            segtree[id].up = min(segtree[id].up, val);
        }
        return;
    }

    combine(id * 2, segtree[id].up, segtree[id].down);
    combine(id * 2 + 1, segtree[id].up, segtree[id].down);
    segtree[id].down = 1e9, segtree[id].up = 0;

    int mid = (cl + cr) / 2;
    update(id * 2, cl, mid, type, ql, qr, val);
    update(id * 2 + 1, mid + 1, cr, type, ql, qr, val);
}

void print_tree(int id, int l, int r) {
    if (l == r) return;

    int mid = (l + r) / 2;
    print_tree(id * 2, l, mid);
    print_tree(id * 2 + 1, mid + 1, r);
}

void calc(int id, int l, int r) {
    if (l == r) {
        ans[l] = min(segtree[id].up, segtree[id].down);
        return;
    }

    int mid = (l + r) / 2;
    combine(id * 2, segtree[id].up, segtree[id].down);
    combine(id * 2 + 1, segtree[id].up, segtree[id].down);

    calc(id * 2, l, mid);
    calc(id * 2 + 1, mid + 1, r);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0, type, l, r, val; i < K; i++) {
        cin >> type >> l >> r >> val;
        update(1, 1, N, type, l + 1, r + 1, val);
    }

    calc(1, 1, N);

    for (int i = 1; i <= N; i++) printf("%d\n", ans[i]);
}
