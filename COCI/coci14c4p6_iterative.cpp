#include <bits/stdc++.h>

#define MAXN 301
#define ll long long
#define INF (1LL << 25)

using namespace std;

inline bool getBit(int n, int idx) { return n & (1 << idx); }
inline int setBit(int n, int idx) { return n | (1 << idx); }
inline int clearBit(int n, int idx) { return n & ~(1 << idx); }

int N, M, K;
ll dp[MAXN][MAXN][(1 << 4)];

int main(){
    scanf("%d%d%d", &N, &M, &K);

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            for (int state = 0; state < (1 << 4); state++){
                if (state == 0){
                    dp[i][j][state] = INF;
                } else {
                    ll ans = (ll)pow(i * j - K, 2);

                    for (int k = 1; k < i; k++){
                        ans = min(ans, dp[k][j][clearBit(state, 0)] + dp[i - k][j][clearBit(state, 1)]);
                    }

                    for (int k = 1; k < j; k++){
                        ans = min(ans, dp[i][k][clearBit(state, 2)] + dp[i][j - k][clearBit(state, 3)]);
                    }

                    dp[i][j][state] = ans;
                }
            }
        }
    }

    cout << dp[N][M][15] << endl;
}
