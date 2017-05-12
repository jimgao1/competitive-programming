
#include <bits/stdc++.h>
#define MAXN 200001

using namespace std;

struct {
	int l, r, val, lazy;
	int nodes() { return r - l + 1; }
} segtree[MAXN * 4];

int N, A[MAXN];

void build(int id, int left, int right){
	node[id].l = left, node[id].r = right;
	node[id].lazy = 0;

	if (left != right){
		int mid = (left + right) / 2;
		build(id * 2, left, mid);
		build(id * 2 + 1, mid + 1, right);

		segtree[id].val = segtree[id * 2].val + segtree[id * 2 + 1].val;
	} else {
		segtree[id].val = A[left];
	}
}

void push_down(int cur){
	if (segtree[cur].left != segtree[cur].right){
		segtree[cur * 2].val += segtree[cur].lazy * segtree[cur * 2].nodes();
		segtree[cur * 2 + 1].val += segtree[cur].lazy * segtree[cur * 2 + 1].nodes();
		segtree[cur * 2].lazy += segtree[cur].lazy;
		segtree[cur * 2 + 1].lazy += segtree[cur].lazy;
	}

	segtree[cur].lazy = 0;
}

void update(int id, int left, int right, int val){
	if (segtree[id].left == left && segtree[id].right == right){
		segtree[id].val += val * segtree[id].nodes();
		segtree[id].lazy += val;
		return;
	}

	if (segtree[id].lazy) push_down(id);

	int mid = (segtree[id].left + segtree[id].right) / 2;
	if (right <= mid){
		update(id * 2, left, right, val);
	} else if (left > mid){
		update(id * 2 + 1, left, right, val);
	} else  {
		update(id * 2, left, right, val);
		update(id * 2 + 1, left, right, val);
	}
}

int query(int id, int left, int right){
	if (segtree[id].left == left && segtree[id].right == right){
		return segtree[id].val;
	}
	if (segtree[id].lazy) push_down(id);
	int mid = (segtree[id].left + segtree[id].right) / 2;
	if (right <= mid){
		return query(id * 2, left, right);
	} else if (left > mid){
		return query(id * 2 + 1, left, right);
	} else {
		return query(id * 2, left, right) + query(id * 2 + 1, left, right);
	}
}

int main(){

}
