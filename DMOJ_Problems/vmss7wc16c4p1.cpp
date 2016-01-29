#include <bits/stdc++.h>

using namespace std;

int main(){
	int A, B, cnt = 0;
	cin >> A >> B;
	
	for (int i = A; i <= B; i++){
		if (sqrt(i) == floor(sqrt(i))) cnt++;
	}
	
	cout << cnt << endl;
}
