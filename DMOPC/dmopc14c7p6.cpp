
/*
Thanks Kirito for helping me recovery the long lost memories of 
the miseries of segtrees
*/

#include <bits/stdc++.h>

#define MAXN 100001

using namespace std;

struct node{
    int left, right, sum, best;
};

int N, num[MAXN];
node segtree[3 * MAXN + 1];

// void build(NodeIndex, LeftIndex, RightIndex);
void build(int idx, int left, int right){
    segtree[idx].left = left;
    segtree[idx].right = right;

    if (left != right){
        int mid = (left + right) / 2;
        build(idx * 2, left, mid);
        build(idx * 2 + 1, mid + 1, right);
    }
}

// void update(NodeIndex, Position, Value);
void update(int idx, int pos, int val){
    int left = segtree[idx].left, right = segtree[idx].right;

    if (left != right){
        int mid = (left + right) / 2;
        if (pos <= mid){
            update(idx * 2, pos, val);
        } else {
            update(idx * 2 + 1, pos, val);
        }

        segtree[idx].best = max(segtree[idx * 2].best,
                                segtree[idx * 2].sum + segtree[idx * 2 + 1].best);

        segtree[idx].sum = segtree[idx * 2].sum + segtree[idx * 2 + 1].sum;
    } else {
        segtree[idx].sum = segtree[idx].best = val;
    }
}

int main(){
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> num[i];

    int ans = 0;
    build(1, 1, N);
    for (int i = 1; 2 * i <= N; i++){
        update(1, num[i * 2], -1);
        update(1, num[i * 2 - 1], -1);
        update(1, num[i], 1);

        if (segtree[1].best <= 0) ans = i;
    }
    cout << ans << endl;
}

