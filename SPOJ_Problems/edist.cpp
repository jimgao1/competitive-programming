
/*
	SPOJ - EDIST

	This is a classical edit distance problem, and it is simple to solve with the
	wagner-fischer edit distance dynamic programming algorithm
*/

#include <iostream>
#include <algorithm>
#include <string>

#define INF 0x3f3f3f3f

using namespace std;

int tc;
int dp[2100][2100];

int tmin(int a, int b, int c){
	return min(min(a, b), c);
}

int main(){
	cin >> tc;

	for (int c = 0; c < tc; c++){
		string s1, s2;
		cin >> s1 >> s2;

		for (int i = 0; i < 2100; i++)
			for (int j = 0; j < 2100; j++)
				dp[i][j] = INF;

		for (int i = 0; i <= s1.length(); i++)
			dp[i][0] = i;

		for (int i = 0; i <= s2.length(); i++)
			dp[0][i] = i;

		for (int i = 1; i <= s1.length(); i++){
			for (int j = 1; j <= s2.length(); j++){
				if (s1[i - 1] == s2[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = tmin(dp[i - 1][j] + 1,
									dp[i][j - 1] + 1,
									dp[i - 1][j - 1] + 1);
			}
		}

		cout << dp[s1.length()][s2.length()] << endl;
	}

	return 0;
}
