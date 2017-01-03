
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

#define MAXN 601

using namespace std;

int W, L, dp[MAXN];
string str, words[MAXN];

int test(string w, int st){
    int cur = 0;
    for (int i = st; i < str.size(); i++){
        if (str[i] == w[cur]){
            cur++;
        }
        if (cur == w.size()) return i;
    }
    return -1;
}

int calc(int idx){
    if (idx >= str.size()) return 0;

    if (dp[idx] != -1) return dp[idx];

    int ans = 1 + calc(idx + 1);
    for (int i = 0; i < W; i++){
        if (str[idx] == words[i][0]){
            int loc = test(words[i], idx);
            if (loc != -1){
                ans = min(ans, (loc - idx + 1 - (int)(words[i].size())) + calc(loc + 1));
            }
        }
    }
    return dp[idx] = ans;
}

int main(){
    memset(dp, -1, sizeof dp);
    cin >> W >> L >> str;
    for (int i = 0; i < W; i++) cin >> words[i];

    cout << calc(0) << endl;
}

