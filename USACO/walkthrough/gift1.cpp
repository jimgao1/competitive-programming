/*
ID: jim3
PROG: gift1
LANG: C++11
*/

#include <bits/stdc++.h>

#define MAXN 11

using namespace std;

int N, balance[MAXN];
vector<string> names;
unordered_map<string, int> dict;

int main(){
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++){
        string name;
        cin >> name;

        names.push_back(name);
        dict[name] = names.size() - 1;
    }

    while(!cin.eof()){
        string name;
        int total, npeople;

        cin >> name >> total >> npeople;
        //if (total == 0 && npeople == 0) break;

        int p = floor((double)total / npeople);
        for (int i = 0; i < npeople; i++){
            string c;
            cin >> c;

            balance[dict[c]] += p;
        }

        balance[dict[name]] -= npeople * p;
    }

    for (string name : names){
        printf("%s %d\n", name.c_str(), balance[dict[name]]);
    }
}

