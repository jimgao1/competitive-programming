
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

#define INF 0x3f3f3f3f

using namespace std;

int dp[101][101], dv[101][101];
string str;

void print(int i, int j){

    if (i > j) return;

    if (i == j){
        if (str[i] == '(' || str[i] == ')')
            cout << "()";
        else
            cout << "[]";
        return;
    }

    if (dv[i][j] == -1){
        cout << str[i];
        print(i + 1, j - 1);
        cout << str[j];

        return;
    }

    print(i, dv[i][j]);
    print(dv[i][j] + 1, j);
}

int solve(int i, int j){
    //printf("i = %d, j = %d\n", i, j);

    if (i == j) return 1;
    if (i > j) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int ans = INF, d = -1;
    if (str[i] == '(' && str[j] == ')') {
        int alt = solve(i + 1, j - 1);
        if (alt < ans){
            ans = alt, d = -1;
        }
    }
    if (str[i] == '[' && str[j] == ']'){
        int alt = solve(i + 1, j - 1);
        if (alt < ans){
            ans = alt, d = -1;
        }
    }

    for (int k = i; k < j; k++){
        int alt = solve(i, k) + solve(k + 1, j);

        if (alt < ans){
            ans = alt;
            d = k;
        }
    }

    dp[i][j] = ans;
    dv[i][j] = d;
    return ans;
}

int main(){
    memset(dp, -1, sizeof dp);
    memset(dv, -1, sizeof dv);

    getline(cin, str);

    solve(0, str.size() - 1);
    print(0, str.size() - 1);
    cout << endl;
}
