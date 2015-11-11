
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int N, M;

struct node{
    int l, r, vmax, vmin;
    int imax, imin;
    bool solved;
};

node tree[2000001];

void build(int cur, int l, int r){
    tree[cur].l = l;
    tree[cur].r = r;

    tree[cur].imax = r;
    tree[cur].imin = l;
    tree[cur].solved = false;

    if (tree[cur].l == tree[cur].r){
        return;
    }

    int mid = (l + r) / 2;
    build(cur * 2, l, mid);
    build(cur * 2 + 1, mid + 1, r);
}

void plusOne(int cur, int idx){
    if (tree[cur].l == tree[cur].r && tree[cur].l == idx){
        tree[cur].vmin += 1;
        tree[cur].vmax += 1;

        return;
    }

    if (tree[cur].l == tree[cur].r) return;

    int mid = (tree[cur].l + tree[cur].r) / 2;
    if (idx <= mid)
        plusOne(cur * 2, idx);
    else
        plusOne(cur * 2 + 1, idx);

    if (tree[cur * 2].vmax < tree[cur * 2 + 1].vmax){
        tree[cur].vmax = tree[cur * 2].vmax;
        tree[cur].imax = tree[cur * 2].imax;
    } else {
        tree[cur].vmax = tree[cur * 2 + 1].vmax;
        tree[cur].imax = tree[cur * 2 + 1].imax;
    }

    if (tree[cur * 2].vmin >= tree[cur * 2 + 1].vmin){
        tree[cur].vmin = tree[cur * 2].vmin;
        tree[cur].imin = tree[cur * 2].imin;
    } else {
        tree[cur].vmin = tree[cur * 2 + 1].vmin;
        tree[cur].imin = tree[cur * 2 + 1].imin;
    }


}

void updateSolved(int cur, int idx){
    if (tree[cur].l == tree[cur].r && tree[cur].l == idx){
        tree[cur].vmax = INF, tree[cur].vmin = -INF;
        tree[cur].solved = true;
        return;
    }

    int mid = (tree[cur].l + tree[cur].r) / 2;
    if (idx <= mid)
        updateSolved(cur * 2, idx);
    else
        updateSolved(cur * 2 + 1, idx);

    if (tree[cur * 2].vmax < tree[cur * 2 + 1].vmax){
        tree[cur].vmax = tree[cur * 2].vmax;
        tree[cur].imax = tree[cur * 2].imax;
    } else {
        tree[cur].vmax = tree[cur * 2 + 1].vmax;
        tree[cur].imax = tree[cur * 2 + 1].imax;
    }

    if (tree[cur * 2].vmin >= tree[cur * 2 + 1].vmin){
        tree[cur].vmin = tree[cur * 2].vmin;
        tree[cur].imin = tree[cur * 2].imin;
    } else {
        tree[cur].vmin = tree[cur * 2 + 1].vmin;
        tree[cur].imin = tree[cur * 2 + 1].imin;
    }

    if (tree[cur * 2].solved && tree[cur * 2 + 1].solved)
        tree[cur].solved;
}

int main(){

    scanf("%d%d", &N, &M);

    build(1, 1, N);

    for (int i = 0, a, b; i < M; i++){
        scanf("%d%d", &a, &b);

        if (a == 1){
            updateSolved(1, b);
        } else {
            plusOne(1, b);
        }

        if (tree[1].vmax >= INF){
            printf("Make noise\n");
        } else {
            printf("%d %d\n", tree[1].imin, tree[1].imax);
        }
    }
}
