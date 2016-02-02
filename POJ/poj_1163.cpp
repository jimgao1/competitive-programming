
#include <iostream>
#include <algorithm>

using namespace std;

int n, numbers[101][101], dp[101][101];

int main(){
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> numbers[i][j];

    for (int i = n - 1; i >= 0; i--){
        for (int j = 0; j <= i; j++){
            if (i == n - 1)
                dp[i][j] = numbers[i][j];
            else
                dp[i][j] = numbers[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
        }
    }

    cout << dp[0][0] << endl;

    return 0;
}
