
#include <bits/stdc++.h>

#define MAXN 100001
#define INF 0x3f3f3f3f

using namespace std;

int N, Q;
int segtree[4 * MAXN], data[MAXN];

void build(int id, int left, int right){
    if (left == right){
        segtree[id] = data[left];
        return;
    }

    int mid = (left + right) / 2;
    build(id * 2, left, mid);
    build(id * 2 + 1, mid + 1, right);

    segtree[id] = min(segtree[id * 2], segtree[id * 2 + 1]);
}

void update(int id, int left, int right, int uid, int val){
    if (left == right){
        segtree[id] = val;
        return;
    }

    int mid = (left + right) / 2;

    if (uid <= mid){
        update(id * 2, left, mid, uid, val);
    } else {
        update(id * 2 + 1, mid + 1, right, uid, val);
    }

    segtree[id] = min(segtree[id * 2], segtree[id * 2 + 1]);
}

int query(int id, int left, int right, int qleft, int qright){
    if (left > qright || right < qleft) return INF;
    if (qleft <= left && qright >= right) return segtree[id];

    int mid = (left + right) / 2;
    return min(query(id * 2, left, mid, qleft, qright),
                query(id * 2 + 1, mid + 1, right, qleft, qright));
}

int main(){
    cin >> N >> Q;
    for (int i = 0; i < N; i++) cin >> data[i];

    build(1, 0, N - 1);

    for (int i = 0; i < Q; i++){
        string cmd;
        int a, b;

        cin >> cmd >> a >> b;

        if (cmd == "Q"){
            cout << query(1, 0, N - 1, a, b) << endl;
        } else {
            update(1, 0, N - 1, a, b);
        }
    }
}
