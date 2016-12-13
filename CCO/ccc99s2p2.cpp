
#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

int T, N, K, place[MAXN];
map<string, int> mp;
vector<pair<string, int>> words;

bool cmp(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

int main(){
    cin >> T;
    while(T--) {
        mp.clear();
        words.clear();
        memset(place, 0, sizeof place);

        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            string str;
            cin >> str;

            mp[str]++;
        }

        for (const auto &p : mp) {
            words.push_back(p);
        }

        sort(words.begin(), words.end(), cmp);

        place[0] = 1;
        for (int i = 1; i < N; i++){
            if (words[i].second == words[i - 1].second){
                place[i] = place[i - 1];
            } else {
                place[i] = i + 1;
            }
        }

        if (K % 10 == 1 && K % 100 != 11) {
            cout << K << "st";
        } else if (K % 10 == 2 && K % 100 != 12) {
            cout << K << "nd";
        } else if (K % 10 == 3 && K % 100 != 13) {
            cout << K << "rd";
        } else {
            cout << K << "th";
        }
        cout << " most common word(s):" << endl;

        for (int i = 0; i < N; i++){
            if (place[i] == K)
                cout << words[i].first << endl;
        }

        cout << endl;

    }
}
