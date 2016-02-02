#include <bits/stdc++.h>

using namespace std;

int D, I, R, dp[1010][1010];
string sa, sb;

int main(){
	cin >> D >> I >> R >> sa >> sb;
	
	for (int i = 0; i <= sa.size(); i++){
		for (int j = 0; j <= sb.size(); j++){
			if (i == 0){
				dp[i][j] = j * I;
			} else if (j == 0){
				dp[i][j] = i * D;
			} else if (sa[i - 1] == sb[j - 1]){
				dp[i][j] = dp[i - 1][j - 1];
			} else {
				dp[i][j] = dp[i - 1][j] + D;
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + I);
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + R);
			}
		}
	}
	
	cout << dp[sa.size()][sb.size()] << endl;
}
