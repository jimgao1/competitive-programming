
#include <bits/stdc++.h>

using namespace std;

int N, cnt[26], tmp[26];
vector<string> str;

int main(){
	cin >> N;
	for (int i = 0; i < N; i++){
		string tmp;
		cin >> tmp;
		cnt[tmp[0] - 'a']++;
		str.push_back(tmp);
	}

	int ans = 0;
	for (int i = 0; i < N; i++){
		cnt[str[i][0] - 'a']--;
		memset(tmp, 0, sizeof tmp);
		for (char c : str[i]){
			tmp[c - 'a']++;
		}

		bool v = true;
		for (int j = 0; j < 26; j++){
			if (tmp[j] > cnt[j]){
				v = false;
				break;
			}
		}
		if (v) ans++;

		cnt[str[i][0] - 'a']++;
	}

	cout << ans << endl;
}
