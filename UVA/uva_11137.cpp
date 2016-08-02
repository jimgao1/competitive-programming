
#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

ull dp[10001];

int main(){
    memset(dp, 0, sizeof dp);

    dp[0] = 1;
    for (int i = 1; i < 22; i++){
        int val = (int)(pow(i, 3));
        for (int j = val; j < 10001; j++){
            dp[j] += dp[j - val];
        }
    }

    int fuck;
    while(cin >> fuck) cout << dp[fuck] << endl;
}
