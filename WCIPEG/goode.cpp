
#include <bits/stdc++.h>

#define MAXN 1000001

using namespace std;

struct node{
    int l, r, val;
    bool lazy;
};

node segtree[3 * MAXN];
int N, M, L;

void push_up(int id){
    segtree[id].val = segtree[id * 2].val + segtree[id * 2 + 1].val;
}

void push_down(int id){
    segtree[id].lazy = false;
    segtree[id * 2].lazy = !segtree[id * 2].lazy;
    segtree[id * 2 + 1].lazy = !segtree[id * 2 + 1].lazy;
    segtree[id * 2].val = segtree[id * 2].r - segtree[id * 2].l + 1 - segtree[id * 2].val;
    segtree[id * 2 + 1].val = segtree[id * 2 + 1].r - segtree[id * 2 + 1].l + 1 - segtree[id * 2 + 1].val;
}

void build(int id, int l, int r){
    segtree[id].l = l, segtree[id].r = r;
    segtree[id].lazy = false;

    if (l == r){
        segtree[id].val = 1;
        return;
    }

    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);

    push_up(id);
}

void update(int id, int l, int r){
    if (segtree[id].l == l && segtree[id].r == r){
        segtree[id].lazy = !segtree[id].lazy;
        segtree[id].val = r - l + 1 - segtree[id].val;
    } else {
        if (segtree[id].lazy) push_down(id);

        int mid = (segtree[id].l + segtree[id].r) / 2;

        if (r <= mid)
            update(id * 2, l, r);
        else if (l > mid && mid != 0)
            update(id * 2 + 1, l, r);
        else if (mid != 0) {
            update(id * 2, l, mid);
            update(id * 2 + 1, mid + 1, r);
        }

        push_up(id);
    }
}

int query(int id, int left){
    if (segtree[id].l == segtree[id].r) return segtree[id].l;
    if (segtree[id].lazy) push_down(id);

    if (left > segtree[id * 2].val)
        return query(id * 2 + 1, left - segtree[id * 2].val);
    return query(id * 2, left);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> L;
    build(1, 1, N);

    for (int i = 0, a, b; i < M; i++){
        cin >> a >> b;
        update(1, a, b);

        if (segtree[1].val < L){
            cout << "AC?" << "\n";
        } else {
            cout << query(1, L) << "\n";
        }
    }
}
