
#include <bits/stdc++.h>

#define MAXN 4001

using namespace std;

int N, a, b, c, dp[MAXN];

void doit(int k){
    for (int i = 0; i <= N; i++){
        if (dp[i] == -1) continue;
        for (int j = 1; i + j * k <= N; j++){
            dp[i + j * k] = max(dp[i + j * k], dp[i] + j);
        }
    }
}

int main(){
    cin >> N >> a >> b >> c;
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    doit(a);
    doit(b);
    doit(c);
    cout << dp[N] << endl;
}

