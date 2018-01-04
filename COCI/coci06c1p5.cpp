
#include <bits/stdc++.h>

#define MAXN 21

using namespace std;

inline bool getBit(int n, int idx) { return n & (1 << idx); }
inline int setBit(int n, int idx) { return n | (1 << idx); }

inline int popcount(int n) {
    int a = 0;
    for (int i = 0; i < MAXN; i++)
        if (getBit(n, i)) a++;
    return a;
}

int N;
double prob[MAXN][MAXN], dp[2][1 << MAXN];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> prob[i][j];
            prob[i][j] /= 100.0;
        }
    }

    for (int i = 0; i < N; i++) {
        int cur = i % 2, prev = (i + 1) % 2;

        for (int j = 0; j < (1 << N); j++) dp[cur][j] = 0;
        for (int j = 0; j < N; j++) dp[cur][1 << j] = prob[i][j];

        for (int j = 0; j < (1 << N); j++) {
            if (popcount(j) != i + 1) continue;
            for (int k = 0; k < N; k++) {
                if (getBit(j, k))
                    dp[cur][j] = max(dp[cur][j], dp[prev][j & (~(1 << k))] * prob[i][k]);
            }
        }
    }

    printf("%.7f\n", dp[(N - 1) % 2][(1 << N) - 1] * 100);
}
