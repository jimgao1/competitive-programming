
#include <bits/stdc++.h>

#define MAXN 100005

using namespace std;

int dset[MAXN];

void uinit(){
	for (int i = 0; i < MAXN; i++){
		dset[i] = i;
	}
}

int ufind(int n){
	int root = n;
	while(root != dset[root]) root = dset[root];
	while(root != n){
		int tmp = dset[n];
		dset[n] = root;
		n = tmp;
	}
	return root;
}

void umerge(int a, int b){
	dset[ufind(a)] = ufind(b);
}

int solve(){
	uinit();
	int ans = 0;
	while(true){
		int a, b;
		if (!(cin >> a)) return -1;
		if (a == -1) break;
		cin >> b;

		if (ufind(a) == ufind(b)) ans++;
		umerge(a, b);
	}
	return ans;
}

int main(){
	while(!cin.eof() && cin.good()){
		int x = solve();
		if (x == -1) break;
		cout << x << endl;
	}
}
