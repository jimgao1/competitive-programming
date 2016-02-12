
#include <bits/stdc++.h>

using namespace std;

int N, numbers[101][101];

bool check(){
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            for (int k = 1; k <= N; k++){
                if (numbers[i][numbers[j][k]] != numbers[numbers[i][j]][k]){
                    return false;
                }

            }
        }
    }

    int identity = -1;

    for (int i = 1; i <= N; i++){
        bool flag = true;

        for (int j = 1; j <= N; j++){
            if (numbers[i][j] != j){
                flag = false;
            }
        }

        if (flag){
            identity = i;
            break;
        }
    }

    if (identity == -1) return false;

    for (int i = 1; i <= N; i++){
        bool flag = false;

        for (int j = 1; j <= N; j++){
            if (numbers[i][j] == identity){
                flag = true;
            }

        }

        if (!flag) return false;
    }

    return true;
}

int main(){
    while(true){
        scanf("%d", &N);

        if (N == 0) break;

        for (int i = 1; i <= N; i++){
            for (int j = 1; j <= N; j++){
                scanf("%d", &numbers[i][j]);
            }
        }

        if (check())
            printf("yes\n");
        else
            printf("no\n");
    }
}
