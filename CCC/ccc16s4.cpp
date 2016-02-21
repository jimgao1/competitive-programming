#include <bits/stdc++.h>

using namespace std;

int N, num[401], sum[401], dp[401][401];

int gsum(int a, int b){
    if (a == 0) return sum[b];
    return sum[b] - sum[a - 1];
}

int r(int i, int j){

    if (i > j) return 0;
    if (i == j) return num[i];
    if (i + 1 == j){
        if (num[i] == num[j]){
            return num[i] + num[j];
        }
        return max(num[i], num[j]);
    }

    if (dp[i][j] != -1) return dp[i][j];

    int ans = 0;

    if (num[i] == num[j]){
        int s = r(i + 1, j - 1);

        if (s == gsum(i + 1, j - 1)){
            ans = num[i] + num[j] + gsum(i + 1, j - 1);
        } else {
            ans = max(max(num[i], num[j]), s);
        }
    }

    for (int k = i; k < j; k++){
        int s1 = r(i, k), s2 = r(k + 1, j);

        if (s1 == s2 && s1 == gsum(i, k) && s2 == gsum(k + 1, j)){
            ans = max(ans, s1 + s2);
            break;
        } else {
            ans = max(ans, max(s1, s2));
        }
    }

    for (int k1 = i + 1; k1 < j; k1++){
        for (int k2 = k1; k2 < j; k2++){
            if (gsum(i, k1 - 1) != gsum(k2 + 1, j)) continue;

            int s1 = r(i, k1 - 1), smd = r(k1, k2), s2 = r(k2 + 1, j);

            if (s1 == s2 && s1 == gsum(i, k1 - 1) && smd == gsum(k1, k2) && s2 == gsum(k2 + 1, j)){
                ans = max(ans, s1 + s2 + smd);
                dp[i][j] = ans;
                return ans;
            } else {
                ans = max(ans, max(max(s1, s2), smd));
            }
        }
    }

    dp[i][j] = ans;
    return ans;
}

int main(){

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &num[i]);

    for (int i = 0; i < N; i++){
        sum[i] = num[i];
        if (i > 0) sum[i] += sum[i - 1];
    }

    memset(dp, -1, sizeof dp);

    printf("%d\n", r(0, N - 1));
}
