
#include <bits/stdc++.h>

#define MAiN 5010

using namespace std;

int N, dp[2][MAiN];
string str;


int main(){
    cin >> N >> str;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if (str[N - j] == str[i - 1])
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
            else
                dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
        }
    }

    cout << N - dp[N % 2][N] << endl;
}
