
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int N, diff[150001][3], dp[150001][3][6];

int ord[6][3] = {
    {0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {2, 0, 1}, {1, 2, 0}, {2, 1, 0}
};

int minDiff(int idx, int person, int order){
    if (idx == N && person == 3) return 0;
    if (idx == N || person == 3) return INF;

    if (dp[idx][person][order] != -1)
        return dp[idx][person][order];

    dp[idx][person][order] =  min(minDiff(idx + 1, person + 1, order),
               minDiff(idx + 1, person, order)) + diff[idx][ord[order][person]];

    return dp[idx][person][order];
}

int main(){
    scanf("%d", &N);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &diff[j][i]);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 6; k++)
                dp[i][j][k] = -1;

    int ans = INF;

    for (int i = 0; i < 6; i++){
        ans = min(ans, minDiff(0, 0, i));
    }

    printf("%d\n", ans);
}
