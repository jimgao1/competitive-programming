
#include <bits/stdc++.h>

#define MAXN 100001

using namespace std;

int N, val[MAXN][4], dp[MAXN][4], grades[4];

int calc(int cur, int grade){
    if (grade == 4 || cur == N) return 0;
    if (dp[cur][grade] != -1) return dp[cur][grade];
    int ans = calc(cur + 1, grade);
    if (val[cur][grades[grade]] != -1)
        ans = max(ans, calc(cur + 1, grade + 1) + val[cur][grades[grade]]);
    return dp[cur][grade] = ans;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < 4; j++){
            cin >> val[i][j];
        }
    }

    for (int i = 0; i < 4; i++) grades[i] = i;

    int ans = 0;
    do{
        memset(dp, -1, sizeof dp);
        ans = max(ans, calc(0, 0));
    } while(next_permutation(grades, grades + 4));

    cout << ans << endl;
}
