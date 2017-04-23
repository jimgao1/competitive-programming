
#include <bits/stdc++.h>

#define MAXN 150

using namespace std;

inline bool getBit(int n, int idx) { if (n < 0) return 0; return n & (1 << idx); }
inline int setBit(int n, int idx) { return n | (1 << idx); }

int R, C, rows[MAXN], dp[MAXN][100][100];
vector<int> valid;

int popcount(int n){
    int ans = 0;
    for (int i = 0; i < C; i++)
        if (getBit(n, i))
            ans++;
    return ans;
}

string toBinary(int n){
    stringstream ss;
    for (int i = 0; i < C; i++){
        ss << getBit(n, i) ? "1" : "0";
    }
    return ss.str();
}

int calc(int cur, int r1, int r2){
    if (cur == R) return 0;
    if (dp[cur][r1][r2] != -1) return dp[cur][r1][r2];

    int row1 = valid[r1], row2 = valid[r2];

    int ans = 0;
    for (int i = 0; i < valid.size(); i++){
        int curRow = valid[i];

        if (curRow & rows[cur]) continue;
        if (curRow & row1) continue;
        if (curRow & row2) continue;

        ans = max(ans, popcount(curRow) + calc(cur + 1, i, r1));
    }

    return dp[cur][r1][r2] = ans;
}

int main(){
    cin >> R >> C;

    for (int i = 0; i < (1 << C); i++){
        bool flag = true;
        for (int j = 0; j < C; j++){
            if (getBit(i, j)){
                if (getBit(i, j - 2) || getBit(i, j - 1) ||
                    getBit(i, j + 1) || getBit(i, j + 2)){
                    flag = false;
                    break;
                }
            }
        }

        if (flag) valid.push_back(i);
    }

    for (int i = 0; i < R; i++){
        string str; cin >> str;
        for (int j = 0; j < C; j++){
            if (str[j] == 'H')
                rows[i] = setBit(rows[i], j);
        }
    }

    memset(dp, -1, sizeof dp);
    cout << calc(0, 0, 0) << endl;
}

