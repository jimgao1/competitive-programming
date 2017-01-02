#include <bits/stdc++.h>

using namespace std;

int N, C;
vector<string> parts;
unordered_map<string, int> dict;
unordered_map<string, int> recipes;
vector<pair<vector<int>, int>> comb;
vector<string> curComb;

int getId(string str){
    if (dict.find(str) == dict.end()){
        dict[str] = parts.size();
        parts.push_back(str);
    }
    return dict[str];
}

int calc(int l, int r){
    if (l > r) return -1;

    vector<int> cur;
    int level = 0, pindex = l;
    for (int i = l; i <= r; i++){
        if (curComb[i] == "("){
            level++;
            if (level == 1){
                pindex = i + 1;
            }
        } else if (curComb[i] == ")"){
            level--;
            if (level == 0){
                int tmp = calc(pindex, i - 1);
                if (tmp != -1) cur.push_back(tmp);
            }
        } else {
            if (level == 0){
                cur.push_back(getId(curComb[i]));
            }
        }
    }

    sort(cur.begin(), cur.end());
    stringstream ss;
    for (int i : cur){
        ss << i << "#";
    }

    return recipes[ss.str()];
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++){
        vector<int> ing;

        while(true){
            string str;
            cin >> str;
            if (str == "+" || str == "(" || str == ")") continue;
            if (str == "=") break;
            ing.push_back(getId(str));
        }
        //Hashing
        sort(ing.begin(), ing.end());
        stringstream ss;
        for (int i : ing) ss << i << "#";

        string result;
        cin >> result;
        recipes[ss.str()] = getId(result);
    }

    cin >> C;
    string line;
    getline(cin, line);
    for (int i = 0; i < C; i++){
        curComb.clear();
        getline(cin, line);
        stringstream ss (line);

        while(!ss.eof()){
            string cur;
            ss >> cur;
            if (cur != "+") curComb.push_back(cur);
        }

        int res = calc(1, curComb.size() - 2);
        cout << parts[res] << "\n";
    }
}
