
#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int T, N, ans, terms[MAXN];
char op[MAXN][64001], ss[] = {'+', '-', '*', '/'};
bool dp[MAXN][64001];
vector<char> signs;

int main(){
    cin >> T;
    while(T--){
        memset(dp, 0, sizeof dp);
        signs.clear();

        cin >> N;
        for (int i = 0; i < N; i++){
            cin >> terms[i];
        }
        cin >> ans;

        dp[0][terms[0] + 32000] = true;
        for (int i = 1; i < N; i++){
            for (int j = -32000; j <= 32000; j++){
                if (!dp[i - 1][j + 32000]) continue;
                int tmp[4] = {
                    j + terms[i], j - terms[i], j * terms[i],
                    (j % terms[i] == 0 ? j / terms[i] : -1e7)
                };

                for (int k = 0; k < 4; k++){
                    if (tmp[k] < -32000 || tmp[k] > 32000) continue;
                    dp[i][tmp[k] + 32000] = true;
                    op[i][tmp[k] + 32000] = k;
                }
            }
        }

        if (!dp[N - 1][ans + 32000]) {
            printf("NO EXPRESSION\n");
            continue;
        }

        int cur = ans;
        for (int i = N - 1; i >= 1; i--){
            signs.push_back(ss[op[i][cur + 32000]]);
            if (op[i][cur + 32000] == 0){
                cur = cur - terms[i];
            } else if (op[i][cur + 32000] == 1){
                cur = cur + terms[i];
            } else if (op[i][cur + 32000] == 2){
                cur = cur / terms[i];
            } else {
                cur = cur * terms[i];
            }
        }
        reverse(signs.begin(), signs.end());

        for (int i = 0; i < N - 1; i++){
            printf("%d%c", terms[i], signs[i]);
        }
        printf("%d=%d\n", terms[N - 1], ans);
    }
}
