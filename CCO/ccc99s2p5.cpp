
#include <bits/stdc++.h>

using namespace std;

string expression;

bool cmp(string a, string b){
    for (int i = 0; i < min(a.size(), b.size()); i++){
        if (a[i] < b[i]) return true;
        if (a[i] > b[i]) return false;
    }
    return a.size() < b.size();
}

vector<string> parse(string str){
    vector<string> ans;

    if (str.size() == 0) return ans;
    if (str.size() == 1) {
        ans.push_back(str);
        return ans;
    }

    int level = 0, pindex = 0;
    vector<string> mulbuf;
    for (int i = 0; i < str.size(); i++){
        if (str[i] == '('){
            level++;
        } else if (str[i] == ')'){
            level--;
        }

        if (level == 0){
            if (str[i] == '+'){
                for (string s : mulbuf)
                    ans.push_back(s);
                mulbuf.clear();
                pindex = i + 1;
                continue;
            }

            vector<string> tmp;
            if (str[i] == ')'){
                vector<string> ss = parse(str.substr(pindex + 1, i - pindex - 1));
                for (string s : ss) tmp.push_back(s);
            } else {
                vector<string> ss = parse(str.substr(pindex, i - pindex + 1));
                for (string s : ss) tmp.push_back(s);
            }
            if (mulbuf.empty()){
                for (string s : tmp)
                    mulbuf.push_back(s);
            } else {
                vector<string> f;
                for (string ss : mulbuf){
                    for (string tt : tmp){
                        f.push_back(string(ss + tt));
                    }
                }
                mulbuf.clear();
                for (string s : f)
                    mulbuf.push_back(s);
            }

            pindex = i + 1;
        }
    }

    for (string s : mulbuf) ans.push_back(s);

    return ans;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> expression;
        vector<string> terms = parse(expression);

        for (int i = 0; i < terms.size(); i++){
            sort(terms[i].begin(), terms[i].end());
        }
        sort(terms.begin(), terms.end(), cmp);

        for (int i = 0; i < terms.size(); i++){
            if (i != 0) printf("+");
            printf("%s", terms[i].c_str());
        }
        printf("\n");
    }
}

