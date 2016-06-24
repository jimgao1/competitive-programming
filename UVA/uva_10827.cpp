
#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int T, N, ans = 0, num[MAXN * 2][MAXN * 2];

int sum(int x1, int y1, int x2, int y2){
    return num[x2][y2] - num[x1 - 1][y2] - num[x2][y1 - 1] + num[x1 - 1][y1 - 1];
}

int main(){
    cin >> T;
    while(T--) {
        memset(num, 0, sizeof num);
        ans = 0;

        cin >> N;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> num[i][j];
            }
        }

        for (int i = 1; i <= N * 2; i++) {
            for (int j = 1; j <= N * 2; j++) {
                num[i][j] = num[(i - 1) % N + 1][(j - 1) % N + 1];
            }
        }

        for (int i = 1; i <= N * 2; i++) {
            for (int j = 1; j <= N * 2; j++) {
                num[i][j] += num[i - 1][j] + num[i][j - 1] - num[i - 1][j - 1];
            }
        }

        for (int x1 = 1; x1 <= N; x1++) {
            for (int y1 = 1; y1 <= N; y1++) {
                for (int x2 = x1; x2 <= N * 2; x2++) {
                    for (int y2 = y1; y2 <= N * 2; y2++) {
                        bool valid = true;

                        if (x2 - x1 + 1 <= N && y2 - y1 + 1 <= N) {
                            ans = max(ans, sum(x1, y1, x2, y2));
                        }
                    }
                }
            }
        }

        cout << ans << endl;
    }
}
