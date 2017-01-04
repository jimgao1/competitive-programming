
/*
    Hi Bruce,
        if you are reading this, can you please tell me when the makeup class is?

    Thanks,
    Jim :)
*/

#include <bits/stdc++.h>

#define MAXN 16

using namespace std;

bool getBit(int n, int idx) { return n & (1 << idx); }
int clearBit(int n, int idx) { return n & ~(1 << idx); }
int setBit(int n, int idx) { return n | (1 << idx); }

int N, speed[MAXN], dp[(1 << MAXN)];

int calc(int state){
    if (state == 0) return 0;
    if (dp[state] != -1) return dp[state];

    int cnt = 0, id;
    for (int i = 0; i < N; i++){
        if (getBit(state, i)) {
            cnt++;
            id = i;
        }
    }

    if (cnt == 1){
        return dp[state] = speed[id];
    }

    int ans = 1e9;
    for (int i = 0; i < N; i++){
        if (!getBit(state, i)) continue;
        for (int j = i + 1; j < N; j++){
            if (!getBit(state, j)) continue;

            int nxt = clearBit(clearBit(state, i), j);
            if (nxt == 0){
                ans = min(ans, max(speed[i], speed[j]));
            } else {
                for (int k = 0; k < N; k++){
                    if (getBit(state, k) && k != i && k != j) continue;

                    int tmp = setBit(nxt, k);
                    ans = min(ans, calc(tmp) + max(speed[i], speed[j]) + speed[k]);
                }
            }
        }
    }

    return dp[state] = ans;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) cin >> speed[i];
    memset(dp, -1, sizeof dp);

    cout << calc((1 << N) - 1) << endl;
}
