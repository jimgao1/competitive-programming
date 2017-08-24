
#include <bits/stdc++.h>

#define MAXN 51
#define ll long long

using namespace std;

int R, C, A[MAXN][MAXN];
ll p[55];

void pre(){
	p[0] = 1;
	for (int i = 1; i < 55; i++)
		p[i] = p[i - 1] * 2;
}

int main(){
	pre();

	cin >> R >> C;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cin >> A[i][j];
		}
	}

	ll ans = 0;
	for (int i = 0; i < R; i++){
		int a = 0, b = 0;
		for (int j = 0; j < C; j++){
			if (A[i][j] == 0){
				a++;
			} else {
				b++;
			}
		}

		ans += p[a] + p[b] - 2;
	}

	for (int j = 0; j < C; j++){
		int a = 0, b = 0;
		for (int i = 0; i < R; i++){
			if (A[i][j] == 0)
				a++;
			else
				b++;
		}

		ans += p[a] + p[b] - 2;
	}

	cout << ans - R * C << endl;
}
