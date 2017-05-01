
#include <bits/stdc++.h>

#define MAXN 200001

using namespace std;

int T = 10, N, dp[MAXN];
string str;
unordered_set<string> words;

int calc(int index){
    if (index == str.size()) return 0;
    if (dp[index] != -1) return dp[index];
    stringstream ss;

    int ans = 1e9;
    for (int i = index; i < str.size(); i++){
        ss << str[i];
        if (words.count(ss.str())){
            ans = min(ans, 1 + calc(i + 1));
        }
    }

    return dp[index] = ans;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> str;
        words.insert(str);
    }

    while(T--){
        memset(dp, -1, sizeof dp);
        cin >> str;
        cout << calc(0) - 1 << "\n";
    }
}
