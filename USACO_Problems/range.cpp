/*
ID: jim.yub1
LANG: C++11
TASK: range
*/

#include <bits/stdc++.h>

using namespace std;

int N, cnt[251][251];
bool field[251][251];

string line;

int getCnt(int x, int y, int r){
	if (x == 0 && y == 0) return cnt[r - 1][r - 1];
	if (x == 0) return cnt[x + r - 1][y + r - 1] - cnt[x + r - 1][y - 1];
	if (y == 0) return cnt[x + r - 1][y + r - 1] - cnt[x - 1][y + r - 1];
	return cnt[x + r - 1][y + r - 1] - cnt[x - 1][y + r - 1] - cnt[x + r - 1][y - 1] + cnt[x - 1][y - 1];
}

int main(){
	freopen("range.in", "r", stdin);
	freopen("range.out", "w", stdout);
	
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> line;
		for (int j = 0; j < line.length(); j++)
			field[j][i] = (line[j] == '1');
	}
	
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (field[i][j]) cnt[i][j] = 1;
			if (i - 1 >= 0) cnt[i][j] += cnt[i - 1][j];
			if (j - 1 >= 0) cnt[i][j] += cnt[i][j - 1];
			if (i - 1 >= 0 && j - 1 >= 0) cnt[i][j] -= cnt[i - 1][j - 1];
		}
	}
	
	for (int k = 2; k <= N; k++){
		int cnt = 0;
		for (int i = 0; i + k <= N; i++){
			for (int j = 0; j + k <= N; j++){
				if (getCnt(i, j, k) >= k * k) cnt++;
			}
		}
		
		if (cnt == 0){
			break;
		}
		cout << k << " " << cnt << endl;
    }
}
