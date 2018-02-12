#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int N, A[MAXN];
double B[MAXN];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> A[j];
        sort(A, A + N);
        B[i] = (N % 2 == 0) ? ((double)A[N / 2] + A[N / 2 + 1]) / 2 : A[N / 2];
    }
    sort(B, B + N);
    cout << ((N % 2 == 0) ? (B[N / 2] + B[N / 2 + 1]) / 2 : B[N / 2]) << endl;
}
