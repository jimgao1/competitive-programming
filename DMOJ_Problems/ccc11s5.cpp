
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

inline bool getBit(int n, int bit) { return n & (1 << bit); }
inline int setBit(int n, int bit) { return n | (1 << bit); }
inline int clearBit(int n, int bit) { return n & ~(1 << bit); }

int N, init = 0, cap = 0, dp[25], pre[25];
bool visited[(1 << 25)];

queue<pair<int, int>> q;

int check(int n){
    memset(dp, 0, sizeof dp);
    memset(pre, 0, sizeof pre);
    int ans = 0;

    for (int i = 0; i < N; i++){
        if (getBit(n, i)){
            dp[i] = 1, pre[i] = i;
        }

        if (i > 0 && getBit(n, i) && getBit(n, i - 1)){
            if (dp[i - 1] + 1 > dp[i]){
                dp[i] = dp[i - 1] + 1;
                pre[i] = pre[i - 1];
            }
        }

        ans = max(ans, dp[i]);
    }

    if (ans >= 4){
        for (int i = 0; i < N; i++){
            if (dp[i] == ans){
                for (int j = pre[i]; j <= i; j++){
                    n = clearBit(n, j);
                }
            }
        }
    }

    return n;
}

void print_bin(int num){
    for (int i = 0; i < N; i++)
        printf("%d", getBit(num, i) ? 1 : 0);
    printf("\n");
}

int main(){
    //memset(mem, 0, sizeof mem);

    scanf("%d", &N);
    for (int i = 0, x; i < N; i++){
        scanf("%d", &x);
        if (x == 1){
            init = setBit(init, i);
        } else {
            cap++;
        }
    }

    q.push({check(init), 0});

    bool flag = false;
    while(!q.empty()){
        int cur = q.front().first, steps = q.front().second;
        q.pop();

        cur = check(cur);

        if (cur == 0){
            printf("%d\n", steps);
            flag = true;
            break;
        }

        if (visited[cur]) continue;
        visited[cur] = true;

        //if (steps > cap) continue;

        for (int i = 0; i < N; i++){
            if (!getBit(cur, i)){
                q.push({setBit(cur, i), steps + 1});
            }
        }
    }
}
