#include <bits/stdc++.h>

using namespace std;

int N;
vector<string> words[26];

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        string str;
        cin >> str;

        words[str[0] - 'a'].push_back(str);
    }

    for (int i = 0; i < 26; i++){
        if (words[i].size() != 0){
            sort(words[i].begin(), words[i].end());

            for (int j = 0; j < words[i].size(); j++){
                if (j == 0)
                    cout << words[i][j];
                else
                    cout << ", " << words[i][j];
            }

            cout << endl;
        }
    }
}
