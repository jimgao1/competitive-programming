#include <bits/stdc++.h>

#define ll long long

using namespace std;

int X, Y, N;
int num[300][300], dp[300][300];

int getSum(int x1, int y1, int x2, int y2){
    return dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
}

int main(){
    cin >> X >> Y >> N;

    for (int i = 1; i <= Y; i++)
        for (int j = 1; j <= X; j++)
            cin >> num[j][i];

    for (int i = 1; i <= X; i++){
        for (int j = 1; j <= Y; j++){
            dp[i][j] = num[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
    }

    int ans = 0;

    for (int i = 1; i <= N; i++){
        for (int cx = 1; cx <= X; cx++){
            for (int cy = 1; cy <= Y; cy++){
                int dx = i, dy = N / i;

                if (cx + dx - 1 <= X && cy + dy - 1 <= Y){
                    ans = max(ans, getSum(cx, cy, cx + dx - 1, cy + dy - 1));
                } else {
                    break;
                }
            }
        }

    }

    cout << ans << endl;
}
