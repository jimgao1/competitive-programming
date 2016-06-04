
#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

int N, ans = 0, num[MAXN], dp[MAXN];

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) cin >> num[i];

    for (int i = 0; i < N; i++){
        dp[i] = num[i];
        for (int j = 0; j < i; j++){
            if (num[i] > num[j])
                dp[i] = max(dp[i], dp[j] + num[i]);
        }

        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
}
