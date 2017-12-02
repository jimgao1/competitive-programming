
#include <bits/stdc++.h>

using namespace std;

struct PrefixSum {
    static const int MAX_SIZE = 1000006;
    int D, S[50], data[MAX_SIZE], tmp[MAX_SIZE];
    int total = 1, cur_dim_size = 1, cur_adj = 1;

    // N: Number of dimensions, A: Dimension sizes, num: data
    void build(int N, int *A, int *num) {
        D = N;
        for (int i = 0; i < N; i++) {
            S[i] = A[i];
            total *= A[i];
        }
        for (int i = 0; i < total; i++) {
            data[i] = num[i];
        }

        for (int i = N - 1; i >= 0; i--) {
            cur_dim_size *= A[i];
            for (int idx = 0; idx < total; idx++) {
                tmp[idx] = data[idx];
                if (idx - cur_adj >= 0 && (idx - cur_adj) / cur_dim_size == idx / cur_dim_size) {
                    tmp[idx] += tmp[idx - cur_adj];
                }
            }
            for (int idx = 0; idx < total; idx++) {
                data[idx] = tmp[idx];
            }
            cur_adj *= A[i];
        }
    }

    int query(int *loc) {
        int idx = 1;
        for (int i = D - 1; i >= 0; i--) {
            idx *= loc[i];
        }
        return data[idx];
    }
};

int main() {

}
