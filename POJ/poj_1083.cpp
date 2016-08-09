
#include <bits/stdc++.h>

#define MAXN 210

using namespace std;

int T, N, dp[MAXN];

int main(){
    cin >> T;
    while(T--){
        memset(dp, 0, sizeof dp);

        cin >> N;
        for (int i = 0, a, b; i < N; i++){
            cin >> a >> b;
            if (b < a) swap(a, b);
            a -= 1, b -= 1;
            dp[a / 2] += 1, dp[(b / 2) + 1] -= 1;
        }

        int ans = dp[0];
        for (int i = 1; i < MAXN; i++){
            dp[i] += dp[i - 1];
            ans = max(ans, dp[i]);
        }

        cout << ans * 10 << endl;
    }
}
