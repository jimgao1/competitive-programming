
#include <bits/stdc++.h>

#define MAXN 5001

using namespace std;

int T = 10, N, w[MAXN];
bool poss[2000001];

int main(){
	while(T--){
		memset(poss, 0, sizeof poss);
		cin >> N;
		for (int i = 0; i < N; i++){
			cin >> w[i];
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				poss[w[i] + w[j]] = poss[w[i] * w[j]] = 1;

		for (int i = 0, x; i < 5; i++){
			cin >> x;
			bool flag = false;
			for (int j = 0; j < N; j++){
				if ((x - w[j] >= 0 && poss[x - w[j]]) || (x % w[j] == 0 && poss[x / w[j]])){
					flag = 1;
					break;
				}
			}
			cout << (flag ? "T" : "F");
		}
		cout << endl;
	}
}
