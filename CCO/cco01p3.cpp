#include <bits/stdc++.h>

#define MAXN 101
#define INF 0x3f3f3f3f

using namespace std;

int T, sum, location, dp[MAXN][MAXN];
vector<int> result;

int find_part(int num, int prev){
    if (num == 0) return 1;
    if (dp[num][prev] != -1) return dp[num][prev];
    int ans = 0;
    for (int i = 1; i <= min(num, prev); i++){
        ans += find_part(num - i, i);
    }
    dp[num][prev] = ans;
    return ans;
}

int find_perm(int sum, int last) { return find_part(sum - last, last); }

int find_number(){
    int temp = 0;
    for (int i = 1; i <= sum; i++){
        if (temp + find_perm(sum, i) >= location){
            location -= temp;
            sum -= i;

            return i;
        }

        temp += find_perm(sum, i);
    }

    return -1;
}

int main(){
    memset(dp, -1, sizeof dp);

    cin >> T;
    while(T--){
        result.clear();
        cin >> sum >> location;

        if (location > find_part(sum, sum)){
            cout << "Too big" << endl;
            continue;
        }

        while(location >= 0){
            int cur = find_number();
            if (cur == -1) break;

            result.push_back(cur);
        }

        bool flag = false;
        cout << "(";
        for (int cur : result){
            if (flag) cout << ",";
            flag = true;

            cout << cur;
        }

        cout << ")" << endl;
    }
}
