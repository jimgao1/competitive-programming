#include <bits/stdc++.h>

using namespace std;

int N, L;
vector<string> letters[30];
vector<string> words;

void gen(int idx, string word){
	if (word.size() > L) return;

	if (idx == N){
		if (word.size() <= L)
			words.push_back(word);
		return;
	}

	gen(idx + 1, word);

	for (string c : letters[idx]){
		gen(idx + 1, word + c);
	}
}

int main(){
	cin >> N >> L;
	for (int i = 0, M; i < N; i++){
		cin >> M;
		for (int j = 0; j < M; j++){
			string c;
			cin >> c;

			letters[i].push_back(c);
		}
	}

	for (string c : letters[0])
        gen(1, c);

	sort(words.begin(), words.end());

	for (string w : words){
		if (w.size() > 0)
			cout << w << endl;
	}
}
