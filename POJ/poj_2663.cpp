
#include <iostream>
#include <cstring>

using namespace std;

int n, dp[31];

int main(){
    memset(dp, 0, sizeof dp);

    dp[0] = 1;
    for (int i = 1; i <= 30; i++){
        if (i % 2 == 0){
            dp[i] = 3 * dp[i - 2];
            for (int j = 0; j <= i - 4; j++)
                if (j % 2 == 0) dp[i] += dp[j] * 2;
        } else {
            dp[i] = 0;
        }
    }

    while(true){
        cin >> n;
        if (n == -1) return 0;

        cout << dp[n] << endl;
    }
}
