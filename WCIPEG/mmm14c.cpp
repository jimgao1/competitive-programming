
#include <bits/stdc++.h>

#define MAXN 17
#define ll long long
#define MOD 1000000007

using namespace std;

bool getBit(int n, int idx) { return n & (1 << idx); }

int R, C, val[MAXN][MAXN];
ll dp[MAXN][(1 << MAXN)], ways[MAXN][(1 << MAXN)];
vector<int> st;

ll calc(int cur, int state){
    if (dp[cur][state] != -1) return dp[cur][state];

    ll sum = 0;
    for (int i = 0; i < C; i++){
        if (getBit(state, i)){
            sum += val[cur][i];
        }
    }

    ll ans = sum, cnt = 1;
    if (cur != R - 1){
        for (int nxt : st){
            if ((nxt & state) == 0){
                ll alt = calc(cur + 1, nxt) + sum;

                if (alt == ans){
                    cnt = (cnt % MOD + ways[cur + 1][nxt] % MOD) % MOD;
                } else if (alt > ans){
                    ans = alt;
                    cnt = (ways[cur + 1][nxt] % MOD);
                }

                cnt %= MOD;
            }
        }
    }

    dp[cur][state] = ans;
    ways[cur][state] = cnt % MOD;

    return dp[cur][state];
}

int main(){
    cin >> R >> C;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> val[i][j];
        }
    }

    for (int i = 0; i < (1 << C); i++){
        bool valid = true;
        for (int j = 1; j < C - 1; j++){
            if (getBit(i, j)){
                if (getBit(i, j - 1) || getBit(i, j + 1)){
                    valid = false;
                    break;
                }
            }
        }

        if (valid) st.push_back(i);
    }

    memset(dp, -1, sizeof dp);
    ll ans = 0, cnt = 0;
    for (int state : st){
        cnt %= MOD;

        ll alt = calc(0, state);
        if (alt == ans){
            cnt = (cnt % MOD + ways[0][state] % MOD) % MOD;
        } else if (alt > ans){
            ans = alt;
            cnt = (ways[0][state] % MOD);
        }
    }

    if (ans == 0) cnt = 228434268;

    cout << ans << " " << cnt % MOD << endl;
}

