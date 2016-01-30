
#include <bits/stdc++.h>

#define MAXN 100001

using namespace std;

int T, cnt[MAXN];
vector<int> num[MAXN];

int main(){
	for (int i = 1; i < MAXN; i++){
		for (int j = i; j < MAXN; j += i){
			cnt[j] ++;
		}
	}
	
	for (int i = 1; i < MAXN; i++){
		num[cnt[i]].push_back(i);
	}
	
	scanf("%d", &T);
	for (int i = 0, K, A, B; i < T; i++){
		scanf("%d%d%d", &K, &A, &B);
		
		if (B < A) swap(A, B);
		
		auto ita = lower_bound(num[K].begin(), num[K].end(), A);
		auto itb = upper_bound(num[K].begin(), num[K].end(), B);
		
		printf("%d\n", itb - ita);
	}
}
