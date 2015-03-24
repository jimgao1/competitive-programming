/*
ID: jim_yub1
LANG: C++11
TASK: holstein
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

#define USACO
#define FILEIN "holstein.in"
#define FILEOUT "holstein.out"

using namespace std;

char letters[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

int getIndex(char n){
	for (int i = 0; i < 16; i++) if (letters[i] == n) return i;
	return -1;
}

int main(){
	#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
	#endif


	int vitCount;
	cin >> vitCount;

	vector<int> req;
	for (int i = 0; i < vitCount; i++){
		int n;
		cin >> n;

		req.push_back(n);
	}

	int solCount;
	cin >> solCount;

	vector<vector<int>> sol;

	for (int i = 0; i < solCount; i++){
		vector<int> v;
		for (int j = 0; j < vitCount; j++){
			int n;
			cin >> n;

			v.push_back(n);
		}
		sol.push_back(v);
	}


	queue<string> search;
	search.push("1");
	search.push("0");

	vector<string> possible;

	while (!search.empty()){
		string current = search.front();
		search.pop();

		if (current.length() == solCount){
			string newStr = "";

			for (int i = 0; i < current.length(); i++)
				if (current[i] == '1') newStr += letters[i];

			possible.push_back(newStr);

			continue;
		}

		if (current.length() > solCount) continue;

		search.push(current + "0");
		search.push(current + "1");
	}

	sort(possible.begin(), possible.end());

	int minLength = 10000;

	vector<string> filt2;

	for (string s : possible){
		int sum[30];

		for (int i = 0; i < 30; i++) sum[i] = 0;

		for (int i = 0; i < s.length(); i++){
			int solutionID = getIndex(s[i]);


			for (int j = 0; j < vitCount; j++)
				sum[j] += sol[solutionID][j];
		}

		bool sat = true;

		for (int i = 0; i < vitCount; i++)
			if (sum[i] < req[i]){
				sat = false;
				break;
			}

		if (sat){
			minLength = min(minLength, (int)(s.length()));
			filt2.push_back(s);
		}
	}


	vector<string> filt;

	for (string s : filt2) if (s.length() == minLength) filt.push_back(s);


	sort(filt.begin(), filt.end());

	cout << minLength;

	for (int i = 0; i < filt[0].length(); i++)
		cout << " " << getIndex(filt[0][i]) + 1;

	cout << endl;


	return 0;
}
