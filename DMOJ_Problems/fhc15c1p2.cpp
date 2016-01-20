#include <bits/stdc++.h>

#define ll long long
#define MAXN 1000050

using namespace std;

int cnt = 1, dict[MAXN][26];

int insert_word(string word){
    int current = 1, ans = 0;
    bool flag = false;

    for (int i = 0; i < word.length(); i++){
        int c = word[i] - 'a';
        if (!flag) ans++;

        if (dict[current][c] == 0){
            dict[current][c] = ++cnt;
            flag = true;
        }

        current = dict[current][c];
    }

    return ans;
}

int main() {
    //freopen("autocomplete.txt", "r", stdin);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for (int c = 0; c < T; c++){
        memset(dict, 0, sizeof dict);
        cnt = 1;

        int N;
        cin >> N;
        ll ans = 0;

        for (int i = 0; i < N; i++){
            string str;
            cin >> str;

            int n = insert_word(str);
            ans += n;
        }

        printf("Case #%d: %lld\n", c + 1, ans);
    }

    return 0;
}
