#include <bits/stdc++.h>

using namespace std;

vector<string> sa, sb, sc;

bool start(string str, string pre){
    if (str.size() < pre.size()) return false;
    for (int i = 0; i < pre.size(); i++)
        if (str[i] != pre[i]) return false;
    return true;
}

bool valid(string word, string section){
    //cout << word << "\t" << section << endl;

    if (word == "" && section == "") return true;

    if (word.length() == 0){
        if (section.size() < 2) return false;
        if (section[0] != 'A' && section[0] != 'B') return false;
        if (section[section.size() - 1] != 'A' &&
            section[section.size() - 1] != 'C') return false;

        for (int i = 0; i < section.size() - 1; i++){
            if (section[i] == section[i + 1]) return false;
            if (section[i] == 'C') return false;
        }

        return true;
    }

    if (section.size() >= 2){
        if (section[section.size() - 1] == section[section.size() - 2])
            return false;
    }

    if (section.size() > 0){
        if (section[0] != 'A' && section[0] != 'B')
            return false;

        //if (word.size() > 0 && section[section.size() - 1] == 'C')
        //    return false;
    }

    for (string pre : sa)
        if (start(word, pre))
            if (valid(word.substr(pre.size()), section + "A"))
                return true;

    for (string pre : sb)
        if (start(word, pre))
            if (valid(word.substr(pre.size()), section + "B"))
                return true;

    for (string pre : sc)
        if (start(word, pre))

            if (valid(word.substr(pre.size()), section + "C"))
                return true;

    return false;
}

int main(){
    sa.push_back("ch");
    sa.push_back("t");
    sa.push_back("m");
    sa.push_back("d");
    sa.push_back("b");
    sa.push_back("bd");
    sa.push_back("r");

    sb.push_back("a");
    sb.push_back("e");
    sb.push_back("i");
    sb.push_back("oo");

    sc.push_back("n");
    sc.push_back("v");
    sc.push_back("f");

    bool flag = true;
    int cnt = 0;

    while(!cin.eof()){
        string word;
        cin >> word;

        for (int i = 0; i < word.size(); i++)
            word[i] = tolower(word[i]);

        flag = flag && valid(word, "");
        cnt++;
    }

    if (flag && cnt >= 2)
        cout << "valid" << endl;
    else
        cout << "invalid" << endl;
}
