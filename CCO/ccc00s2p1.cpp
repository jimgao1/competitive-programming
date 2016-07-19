
#include <bits/stdc++.h>

using namespace std;

int N;
bool visited[26];
vector<char> used, sets[26], elements[26];

vector<char> evaluate(char s){
    if (visited[s - 'A']){
        vector<char> e;
        return e;
    }
    visited[s - 'A'] = true;

    vector<char> result;
    for (char c : sets[s - 'A']){
        vector<char> r = evaluate(c);
        for (char cc : r)
            result.push_back(cc);
    }

    for (char c : elements[s - 'A']){
        result.push_back(c);
    }

    return result;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        char a, b;
        string c;
        cin >> a >> c >> b;

        used.push_back(a);

        if (b >= 'a' && b <= 'z'){
            elements[a - 'A'].push_back(b);
        } else {
            sets[a - 'A'].push_back(b);
            used.push_back(b);
        }
    }

    sort(used.begin(), used.end());
    used.erase(unique(used.begin(), used.end()), used.end());

    for (char s : used){
        memset(visited, 0, sizeof visited);
        vector<char> e = evaluate(s);
        sort(e.begin(), e.end());
        e.erase(unique(e.begin(), e.end()), e.end());

        printf("%c = {", s);
        bool flag = false;

        for (char ee : e){
            if (flag) printf(",");
            printf("%c", ee);
            flag = true;
        }

        printf("}\n");
    }
}
