#include <bits/stdc++.h>

#define MAXN 301
#define ll long long

using namespace std;

inline bool getBit(int n, int idx) { return n & (1 << idx); }
inline int setBit(int n, int idx) { return n | (1 << idx); }
inline int clearBit(int n, int idx) { return n & ~(1 << idx); }

int N, M, K;
ll dp[MAXN][MAXN][(1 << 4)];

ll calc(int r, int c, int mask){
    if (mask == 0) return 1e15;
    if (dp[r][c][mask] != -1) return dp[r][c][mask];

    ll ans = (ll)(r * c - K) * (r * c - K);

    for (int i = 1; i < r; i++){
        ll alt = calc(i, c, clearBit(mask, 0)) + calc(r - i, c, clearBit(mask, 1));
        if (alt >= 1e15) break;
        ans = min(ans, alt);
    }

    for (int i = 1; i < c; i++){
        ll alt = calc(r, i, clearBit(mask, 2)) + calc(r, c - i, clearBit(mask, 3));
        if (alt >= 1e15) break;
        ans = min(ans, alt);
    }

    return dp[r][c][mask] = ans;
}

int main(){
    scanf("%d%d%d", &N, &M, &K);
    memset(dp, -1, sizeof dp);
    printf("%lld\n", calc(N, M, 15));
}
