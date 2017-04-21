#include <bits/stdc++.h>

#define MAXN 125
#define ll long long

using namespace std;

ll dp[MAXN], prefix[MAXN];
vector<ll> ids;

string doit(int len, ll id){
    if (len == 0) return "";
    if (len < 2) return "";
    //Try 420 first
    ll cc = dp[len - 3];
    if (cc > id && len >= 3){
        return "420" + doit(len - 3, id);
    }
    return "69" + doit(len - 2, id - cc);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i < MAXN; i++){
        dp[i] = dp[i - 2] + dp[i - 3];
    }

    for (int i = 1; i < MAXN; i++){
        prefix[i] = prefix[i - 1] + dp[i];
        ids.push_back(prefix[i]);
    }

    int T;
    cin >> T;
    while(T--){
        ll id;
        cin >> id;
        ll len = (lower_bound(ids.begin(), ids.end(), id) - ids.begin()) + 1;

        //printf("len = %lld, begin = %lld\n", len, prefix[len - 1] + 1);
        cout << doit(len, id - (prefix[len - 1] + 1)) << "\n";
    }
}
