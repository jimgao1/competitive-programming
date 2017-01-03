

#include <cstdio>
#include <queue>
#include <cstring>
#include <set>

#define MAXN 60005

using namespace std;

int n[6], total = 0;
bool dp[MAXN], tmp[MAXN];

bool test(){
    if (total % 2 == 1) return false;
    dp[0] = true;
    for (int i = 0; i < 6; i++){
        memset(tmp, 0, sizeof tmp);
        for (int j = 0; j < MAXN; j++){
            if (dp[j]){
                if (j == total / 2) return true;
                for (int k = 1; k <= n[i]; k++){
                    int nxt = j + k * (i + 1);
                    if (nxt == total / 2) return true;

                    if (nxt < MAXN) tmp[nxt] = true;
                }
            }
        }

        for (int j = 0; j < MAXN; j++){
            dp[j] |= tmp[j];
        }
    }

    return dp[total / 2];
}

int main(){
    int cur = 1;
    while(true){
        memset(dp, 0, sizeof dp);
        total = 0;
        for (int i = 0; i < 6; i++) {
            scanf("%d", &n[i]);
            total += (i + 1) * n[i];
        }

        if (total == 0) break;

        printf("Collection #%d:\n", cur++);
        if (test()){
            printf("Can be divided.\n");
        } else {
            printf("Can't be divided.\n");
        }
        printf("\n");
    }
}

