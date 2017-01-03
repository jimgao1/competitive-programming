
#include <bits/stdc++.h>

#define MAXN 3200
#define ll long long

using namespace std;

int N, M, pa[MAXN], pb[120];
int dp[MAXN][120][120][2];

int f(int cur, int l, int r, int taken){
    //printf("cur = %d, l = %d, r = %d, taken = %d\n", cur, l, r, taken);

    if (dp[cur][l][r][taken] != -1)
        return dp[cur][l][r][taken];

    int ans = 0;

    //Case 5: at the end of the line
    if (cur == N){
        //Check if the second pile is empty
        if (l > r){
            return ans = 0;
        } else {
            if (taken){
                return dp[cur][l][r][taken] = f(cur, l + 1, r, 0);
            } else {
                return dp[cur][l][r][taken] = pb[r] + f(cur, l, r - 1, 1);
            }
        }
    }

    if (taken){
        //Case 2: skip the current pie
        ans = f(cur + 1, l, r, 0);

        if (l <= r){
            //Case 3: insert separator
            ans = max(ans, f(cur, l + 1, r, 0));
        }
    } else {
        //Case 1: take the current pie
        ans = pa[cur] + f(cur + 1, l, r, 1);

        //Case 2: skip the current pie
        ans = max(ans, f(cur, l, r, 1));

        if (l <= r){
            //Case 4: eat pie from pb
            ans = max(ans, pb[r] + f(cur, l, r - 1, 1));
        }
    }


    return dp[cur][l][r][taken] = ans;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> pa[i];
    }
    cin >> M;
    for (int i = 1; i <= M; i++){
        cin >> pb[i];
    }
    sort(pb + 1, pb + M + 1);
    memset(dp, -1, sizeof dp);

    cout << f(0, 1, M, 0) << endl;
}

