
#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int N, ans = 0, num[MAXN][MAXN];

int sum(int x1, int y1, int x2, int y2){
    return num[x2][y2] - num[x1 - 1][y2] - num[x2][y1 - 1] + num[x1 - 1][y1 - 1];
}

int main(){
    cin >> N;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            cin >> num[i][j];
        }
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            num[i][j] += num[i - 1][j] + num[i][j - 1] - num[i - 1][j - 1];
        }
    }

    for (int x1 = 1; x1 <= N; x1++){
        for (int y1 = 1; y1 <= N; y1++){
            for (int x2 = x1; x2 <= N; x2++){
                for (int y2 = y1; y2 <= N; y2++){
                    ans = max(ans, sum(x1, y1, x2, y2));
                }
            }
        }
    }

    cout << ans << endl;
}
