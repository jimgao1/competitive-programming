
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int C, G, location[21], length[21], dp[20][15001];

int main(){
    while(true){
        if (scanf("%d %d", &C, &G) == EOF) break;
        for (int i = 1; i <= C; i++) scanf("%d", &location[i]);
        for (int i = 1; i <= G; i++) scanf("%d", &length[i]);

        memset(dp, 0, sizeof dp);

        dp[0][7500] = 1;

        for (int i = 1; i <= G; i++){
            for (int j = 1; j <= C; j++){
                for (int v = 0; v < 15000; v++){
                    if (dp[i - 1][v] != 0)
                        dp[i][location[j] * length[i] + v] += dp[i - 1][v];
                }
            }
        }

        printf("%d\n", dp[G][7500]);
    }
}
