#include <bits/stdc++.h>

using namespace std;

string a, b, c;
map<char, char> mp;

int main(){
	cin >> a >> b >> c;
	for (int i = 0; i < 26; i++){
		mp[a[i]] = b[i];
		mp[a[i] + 'A' - 'a'] = b[i] + 'A' - 'a';
	}
	for (int i = 0; i < 10; i++) mp['0' + i] = '0' + i;

	for (char cc : c){
		printf("%c", mp[cc]);
	}
	printf("\n");
}
