#include <bits/stdc++.h>

using namespace std;

int N = 0, dp[1001], prv[1001];
vector<pair<pair<int, int>, int>> d;

int main(){
    memset(dp, 0, sizeof dp);
    memset(prv, -1, sizeof prv);

    while(!cin.eof()){
        int a, b;
        cin >> a >> b;
        d.push_back({{a, b}, N++});
    }

    sort(d.begin(), d.end());

    for (int i = 0; i < d.size(); i++){
        dp[i] = 1;

        for (int j = 0; j < i; j++){
            if (d[i].first.first != d[i].first.second && d[j].first.second > d[i].first.second){
                if (dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    prv[i] = j;
                }
            }
        }
    }

    int mlength = 0, mindex = -1;
    for (int i = 0; i < d.size(); i++)
        if (mlength < dp[i]){
            mlength = dp[i];
            mindex = i;
        }

    stack<int> ans;
    while(true){
        if (mindex == -1) break;

        ans.push(mindex);
        mindex = prv[mindex];
    }

    printf("%d\n", mlength);
    while(!ans.empty()) { printf("%d\n", d[ans.top()].second + 1); ans.pop(); }
}
