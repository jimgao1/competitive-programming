
#include <bits/stdc++.h>

using namespace std;

int N;
string st;

bool good(string s){
    stack<char> p;

    for (int i = 0; i < s.length(); i++){
        if (s[i] == '(' || s[i] == '['){
            p.push(s[i]);
        } else if (st[i] == ')' || st[i] == ']'){
            if (p.empty()) return false;

            if (s[i] == ')'){
                if (p.top() != '(') return false;
            } else {
                if (p.top() != '[') return false;
            }

            p.pop();
        }
    }

    return p.empty();
}

int main(){
    cin >> N;
    getline(cin, st);

    while(N--){
        getline(cin, st);

        cout << (good(st) ? "Yes" : "No") << endl;
    }
}
