/*
ID: jim_yub1
LANG: C++11
TASK: inflate
*/

#include <bits/stdc++.h>

using namespace std;

int dp[10001];
int weight[10001], value[10001];

int m, n;

int main(){
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);

    memset(dp, 0, sizeof(dp));

    cin >> m >> n;

    for (int i=0; i<n; i++)
        cin >> value[i] >> weight[i];

    for (int i=1; i<m + 1; i++){
        dp[i] = dp[i - 1];

        for (int j=0; j<n; j++)
            if (i >= weight[j])
                dp[i] = max(dp[i], dp[i - weight[j]] + value[j]);
    }

    cout << dp[m] << endl;

    return 0;
}
