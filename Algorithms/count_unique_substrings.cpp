
#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b){
    for (int i = 0; i < min(a.length(), b.length()); i++)
        if (a[i] != b[i])
            return a[i] < b[i];
    return a.length() < b.length();
}

int countSubstrings(string str){
    vector<string> sub;

    for (int i = 0; i < str.length(); i++){
        sub.push_back(str.substr(i, str.length() - i));
    }

    sort(sub.begin(), sub.end(), cmp);
    int cnt = sub[0].length();

    for (int i = 0; i < sub.size() - 1; i++){
        int scnt = 0;

        for (int j = 0; j < min(sub[i].length(), sub[i + 1].length()); j++){
            if (sub[i][j] == sub[i + 1][j])
                scnt++;
            else
                break;
        }

        cnt += (sub[i + 1].length() - scnt);
    }

    return cnt + 1;
}

int main(){

}
