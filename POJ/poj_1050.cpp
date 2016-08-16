
#include <bits/stdc++.h>

#define MAXN 110

using namespace std;

int N, ans = 0, num[MAXN][MAXN], sum[MAXN][MAXN];

int main(){
    cin >> N;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cin >> num[i][j];
        }
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            sum[i][j] = num[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    for (int x1 = 1; x1 <= N; x1++){
        for (int y1 = 1; y1 <= N; y1++){
            for (int x2 = x1; x2 <= N; x2++){
                for (int y2 = y1; y2 <= N; y2++){
                    int val = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];

                    ans = max(ans, val);
                }
            }
        }
    }

    cout << ans << endl;
}
