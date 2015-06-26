
#include <bits/stdc++.h>

using namespace std;

long dp[1000][1000];

int lcs(string a, string b){
    for (int i = 0; i <= a.length(); i++){
        for (int j = 0; j <= b.length(); j++){
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[a.length()][b.length()];
}

int main(){

    string a, b;
    cin >> a >> b;
    
    cout << lcs(a, b) << endl;

    return 0;
}
