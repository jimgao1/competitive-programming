#include <bits/stdc++.h>

using namespace std;

int cnt[26], ast = 0;

bool check(){
    for (int i = 0; i < 26; i++){
        if (cnt[i] < 0) return false;
        ast -= cnt[i];
    }

    if (ast == 0) return true;
    return false;
}

int main(){
    string s1, s2;
    cin >> s1;

    for (int i = 0; i < s1.size(); i++){
        cnt[s1[i] - 'a'] ++;
    }

    cin >> s2;

    for (int i = 0; i < s2.size(); i++){
        if (s2[i] == '*'){
            ast++;
        } else {
            cnt[s2[i] - 'a'] --;
        }
    }

    cout << (check() ? "A" : "N") << endl;
}
