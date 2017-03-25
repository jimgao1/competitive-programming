
#include <bits/stdc++.h>

#define SEED 31

using namespace std;

int N, M;
unordered_map<int, vector<int>> pre, word;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++){
        string str; cin >> str;

        int hash = 1;
        for (int j = 0; j < str.size(); j++){
            hash = (hash * SEED + str[j] - 'a');
            pre[hash].push_back(i);
        }
        word[hash].push_back(i);
    }

    for (int i = 0; i < M; i++){
        string str; int l, r, hash = 1;
        cin >> str >> l >> r;
        l--, r--;

        int cnt = 0;
        for (int j = 0; j < str.size() - 1; j++){
            hash = (hash * SEED + str[j] - 'a');

            cnt += upper_bound(word[hash].begin(), word[hash].end(), r) -
                    lower_bound(word[hash].begin(), word[hash].end(), l);
        }
        hash = (hash * SEED + str[str.size() - 1] - 'a');
        cnt += upper_bound(pre[hash].begin(), pre[hash].end(), r) -
               lower_bound(pre[hash].begin(), pre[hash].end(), l);

        cout << cnt << "\n";
    }
}
