
#include <bits/stdc++.h>

#define MAXN 501

using namespace std;

int N, sum[MAXN][MAXN];
bool grid[MAXN][MAXN];

int gsum(int r1, int c1, int r2, int c2){
    return sum[r2][c2] - sum[r1 - 1][c2] - sum[r2][c1 - 1] + sum[r1 - 1][c1 - 1];
}

int main(){
    cin >> N;
    for (int i = 1; i <= N; i++){
        string line;
        cin >> line;
        for (int j = 1; j <= N; j++){
            if (line[j - 1] == '#'){
                grid[i][j] = true, sum[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            sum[i][j] += (sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1]);
        }
    }

    for (int k = N - 1; k >= 0; k--){
        for (int i = 1; i + k <= N; i++){
            for (int j = 1; j + k <= N; j++){
                if (gsum(i, j, i, j + k) == 0 &&
                    gsum(i, j, i + k, j) == 0 &&
                    gsum(i + k, j, i + k, j + k) == 0 &&
                    gsum(i, j + k, i + k, j + k) == 0){

                    cout << k << endl;
                    return 0;
                }
            }
        }
    }
}
