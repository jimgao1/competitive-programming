
#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

int N, matrix[MAXN][MAXN];

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < N; i++){
        int num = 0;

        for (int j = 0; j < N; j++){
            num = num | matrix[i][j];
            num = num | matrix[j][i];
        }

        printf("%d ", num);
    }
    printf("\n");
}
