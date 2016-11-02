

#include <bits/stdc++.h>

using namespace std;

int cards[6], f[6], dp[5][5][5][5][5][5];

void winning(int sum){
    bool flag = false;
    for (int i = 0; i < 6; i++){
        if (sum + (i + 1) <= 31 && cards[i] > 0){
            cards[i] --;
            if (dp[cards[0]][cards[1]][cards[2]][cards[3]][cards[4]][cards[5]] == 0){
                winning(sum + i + 1);
            }

            if (dp[cards[0]][cards[1]][cards[2]][cards[3]][cards[4]][cards[5]] == -1){
                cards[i] ++;
                dp[cards[0]][cards[1]][cards[2]][cards[3]][cards[4]][cards[5]] = 1;
                flag = true;
            } else {
                cards[i] ++;
            }
        }
    }

    if (!flag)
        dp[cards[0]][cards[1]][cards[2]][cards[3]][cards[4]][cards[5]] = -1;
}

int main(){
    //freopen("game31.txt", "r", stdin);

    int T;
    string str;
    cin >> T;
    //getline(cin, str);
    while(T--){
        getline(cin, str);
        cin >> str;

        for (int i = 0; i < 6; i++) {
            cards[i] = 4;
            f[i] = 4;
        }
        memset(dp, 0, sizeof dp);

        int s = 0;
        for (int i = 0; i < str.size(); i++){
            int n = str[i] - '1';
            cards[n] --;
            f[n] --;
            s += (n + 1);
        }

        winning(s);
        bool w = (dp[f[0]][f[1]][f[2]][f[3]][f[4]][f[5]] == 1);
        if (str.size() % 2 == 1) w = !w;
        cout << (w ? "A" : "B") << endl;
    }
}

