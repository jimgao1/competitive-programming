
#include <bits/stdc++.h>

using namespace std;

#define MAXN 1001
#define LOGMAXN 15

struct SparseTable {
	int N, K, table[MAXN][LOGMAXN];

	SparseTable(int* nums, int len) {
		for (int i = 0; i < len; i++) {
			table[0][i] = nums[i];
		}

		N = len;
		K = floor(log2(N));
		for (int k = 1; k <= K; k++) {
			for (int i = 0; i < N; i++) {
				table[k][i] = min(table[k - 1][i], table[k - 1][i + (i << (k - 1))]);
			}
		}
	}

	int rangeMinimum(int l, int r){
		int len = r - l + 1;
		int k = floor(log2(len));
		int mid = r - (1 << k) + 1;

		return min(table[k][l], table[k][mid]);
	}
};

int main() {
	int x[] = {1, 5, 2, 4, 7};
	SparseTable t(x, 5);

	while(true){
		int l, r;
		cin >> l >> r;
		cout << t.rangeMinimum(l, r) << endl;
	}
}
