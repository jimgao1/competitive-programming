#include <bits/stdc++.h>

#define MAXN 100001

using namespace std;

int N, num[MAXN], dp[40], ans = 0;
vector<int> vv[40];

int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &num[i]);

	for (int i = 0; i < N; i++){
        int cur = 1;

		for (int j = 0; j <= 31; j++){
			if ((num[i] & (1 << j)) != 0){
				cur = max(cur, dp[j] + 1);
			}
		}

		for (int j = 0; j <= 31; j++){
            if ((num[i] & (1 << j)) != 0){
                dp[j] = max(dp[j], cur);
            }
		}

		ans = max(ans, cur);
	}

	printf("%d\n", ans);
}
