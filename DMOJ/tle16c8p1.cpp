#include <bits/stdc++.h>

using namespace std;

string str;
int N;

int main(){
    cin >> str >> N;
    while(N--){
        string cur;
        cin >> cur;

        int idx = 1;
        for (int i = 1; i < cur.size(); i++){
            if (cur[i] == str[idx]){
                idx++;
            }
        }

        cout << (idx == str.size() ? "yes" : "no") << endl ;
    }
}
