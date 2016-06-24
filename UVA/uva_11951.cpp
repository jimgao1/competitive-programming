
#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int T, N, M, K, num[MAXN][MAXN];

int sum(int x1, int y1, int x2, int y2){
    return num[x2][y2] - num[x1 - 1][y2] - num[x2][y1 - 1] + num[x1 - 1][y1 - 1];
}

int main(){
    cin >> T;

    for (int cc = 0; cc < T; cc++) {
        int area = 0, cost = 0;
        memset(num, 0, sizeof num);

        cin >> N >> M >> K;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> num[i][j];
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                num[i][j] += num[i - 1][j] + num[i][j - 1] - num[i - 1][j - 1];
            }
        }

        for (int x1 = 1; x1 <= N; x1++) {
            for (int y1 = 1; y1 <= M; y1++) {
                for (int x2 = x1; x2 <= N; x2++) {
                    for (int y2 = y1; y2 <= M; y2++) {
                        if (sum(x1, y1, x2, y2) <= K) {
                            if (area < (x2 - x1 + 1) * (y2 - y1 + 1)) {
                                area = (x2 - x1 + 1) * (y2 - y1 + 1);
                                cost = sum(x1, y1, x2, y2);
                            } else if (area == (x2 - x1 + 1) * (y2 - y1 + 1)) {
                                cost = min(cost, sum(x1, y1, x2, y2));
                            }
                        }
                    }
                }
            }
        }

        printf("Case #%d: %d %d\n", cc + 1, area, cost);
    }
}
