
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

#define MAXN 5001

using namespace std;

string str;
short dp[MAXN][MAXN];

short pal(int left, int right){
    if (left >= right) return 0;
    if (dp[left][right] != -1) return dp[left][right];

    if (str[left] == str[right]) return dp[left][right] = pal(left + 1, right - 1);
    return dp[left][right] = min(pal(left + 1, right) + (short)1, pal(left, right - 1) + (short)1);
}

int main(){
    int N;
    cin >> N >> str;

    memset(dp, -1, sizeof dp);

    cout << pal(0, N - 1) << endl;
}
