
#include <bits/stdc++.h>

#define MAXN 100005
#define LOGMAXN 16

using namespace std;

int N, R, A[MAXN];

struct SparseTable {
	int N, K, table[MAXN][LOGMAXN];

	SparseTable() {
		for (int i = 0; i < N; i++) {
			table[0][i] = A[i];
		}

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

int main(){
	cin >> N >> R;
	for (int i = 0; i < N; i++) cin >> A[i];
	SparseTable fuck;

	for (int i = 0; i < N; i++){
		int m = fuck.rangeMinimum(i, min(i + R, N - 1));
		printf("i = %d, m = %d\n", i, m);
		if (m < A[i]){
			bool fucked = false;
			for (int j = i + R; j > i; j--){
				if (A[j] == m){
					A[j] = A[i];
					break;
				}
			}
			A[i] = m;
			break;
		}
	}

	for (int i = 0; i < N; i++) printf("%d ", A[i]);
	printf("\n");
}
