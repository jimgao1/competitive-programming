#include <bits/stdc++.h>

using namespace std;

bool good(string s) {
    stack<char> p;

    bool used = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            p.push(s[i]);
        } else if (s[i] == ')') {
            if (p.empty()){
                if (!used){
                    used = true;
                    p.push('(');
                } else return false;
            } else {
                if (s[i] == ')') {
                    if (p.top() != '(') {
                        if (!used) {
                            used = true;
                        } else return false;
                    }
                }

                p.pop();
            }
        }
    }

    return p.size() == 0 || (!used && p.size() == 2);
}

int main() {
    string str;
    cin >> str;

    if (good(str)) {
        cout << "YES" << endl;
        return 0;
    }


    cout << "NO" << endl;
}
