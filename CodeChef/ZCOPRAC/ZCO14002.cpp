
#include <bits/stdc++.h>

#define MAXN 200001

using namespace std;

int N, val[MAXN], dp[MAXN];

int calc(int cur){
    if (cur >= N) return 0;
    if (dp[cur] != -1) return dp[cur];
    int ans = 1e9;
    for (int i = 1; i <= 3; i++){
        ans = min(ans, val[cur] + calc(cur + i));
    }
    return dp[cur] = ans;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) cin >> val[i];

    memset(dp, -1, sizeof dp);
    cout << min(calc(0), min(calc(1), calc(2))) << endl;
}

