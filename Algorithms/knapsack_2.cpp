/*
	"The Knapsack Template that is NOT disgusting :P

	Coded by Jim Gao while holding 3 breaths on
	Sat Nov 21st, 2015
*/

#include <bits/stdc++.h>

using namespace std;

int N, v[1001], w[1001], dp[1001][1001];

int main(){
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d%d", &v[i], &w[i]);

	for (int i = 1; i <= N; i++)
		for (int j = 0; j <= W; j++)
			if (w[i] > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);

	int ans = 0;

	for (int i = 0; i <= W; i++)
		ans = max(ans, dp[N][i]);

	printf("%d\n", ans);
}
