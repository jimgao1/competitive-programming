#include <iostream>

using namespace std;

int dp[1000001];
int n;

int main(){
    dp[0] = 1, dp[1] = 1;

    cin >> n;

    for (int i=2; i<=n; i++)
        if (i % 2 == 1)
            dp[i] = dp[i - 1];
        else
            dp[i] = (dp[i - 2] + dp[i / 2]) % 1000000000;

    cout << dp[n] << endl;

    return 0;
}
