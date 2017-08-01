#include <bits/stdc++.h>

using namespace std;

int N, A, B;
int a, b, c, ans;

int main(){
	cin >> N >> A >> B;
	a = A, c = B;
	for (int i = 0, x; i < N; i++){
		cin >> x;
		if (x == 1){
			if (a > 0){
				a--;
			} else if (c > 0){
				c--; 
				b++;
			} else if (b > 0){
				b--;
			} else {
				ans++;
			}
		} else {
			if (c > 0){
				c--;
			} else {
				ans += 2;
			}
		}
	}

	cout << ans << endl;
}
