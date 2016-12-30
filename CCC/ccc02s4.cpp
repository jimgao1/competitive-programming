
#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int M, Q, dp[MAXN], speed[MAXN], pre[MAXN];
string names[MAXN];

int main(){
    cin >> M >> Q;
    for (int i = 0; i < Q; i++){
        cin >> names[i] >> speed[i];
    }

    //Let dp[i] be the earliest possible time when person i is about to cross
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 0; i < Q; i++){
        int mspeed = 0;
        for (int j = 0; j < M && i + j <= Q; j++){
            mspeed = max(mspeed, speed[i + j]);
            int alt = dp[i] + mspeed;
            if (alt < dp[i + j + 1]){
                dp[i + j + 1] = alt;
                pre[i + j + 1] = i;
            }
        }
    }

    printf("Total Time: %d\n", dp[Q]);
    vector<int> idx;
    int cur = Q;
    while(true){
        idx.push_back(cur);
        if (cur == 0) break;
        cur = pre[cur];
    }
    reverse(idx.begin(), idx.end());

    for (int i = 0; i < idx.size() - 1; i++){
        for (int j = idx[i]; j < idx[i + 1]; j++){
            cout << names[j] << " ";
        }
        cout << endl;
    }

}

