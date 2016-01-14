
#include <bits/stdc++.h>

using namespace std;

int N, diff[21];
vector<int> num;

int main(){
    while(true){
        num.clear();
        memset(diff, 0, sizeof diff);

        scanf("%d", &N);

        if (N == 0) break;

        for (int i = 0, x; i < N; i++){
            scanf("%d", &x);
            num.push_back(x);
        }

        if (N == 1){
            printf("0\n");
            continue;
        }

        for (int i = 0; i < N - 1; i++){
            diff[i] = num[i + 1] - num[i];
        }

        for (int i = 1; i <= N - 1; i++){
            bool valid = true;
            for (int j = 0; j < N - 1; j++){
                if (diff[j] != diff[j % i]){
                    valid = false;
                    break;
                }
            }

            if (valid){
                printf("%d\n", i);
                break;
            }
        }
    }
}

