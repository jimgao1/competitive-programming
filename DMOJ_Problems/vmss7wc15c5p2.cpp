
#include <bits/stdc++.h>

#define nodeCount 52

using namespace std;

int N, in[26];
bool visited[26], used[26], matrix[101][101];
set<char> elements[26], sets[26];

inline int id(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 26;
    return c - 'A';
}

int main(){
    memset(visited, 1, sizeof visited);
    memset(matrix, 0, sizeof matrix);

    cin >> N;
    for (int i = 0; i < N; i++){
        char sa, sb;
        string temp;
        cin >> sa >> temp >> sb;

        used[sa - 'A'] = true;

        if (sb >= 'A' && sb <= 'Z'){
            sets[sa - 'A'].insert(sb);
            used[sb - 'A'] = true;
        } else {
            elements[sa - 'A'].insert(sb);
        }
    }

    while(true){
        bool flag = false;

        for (int i = 0; i < 26; i++){
            if (!used[i]) continue;
            int s = elements[i].size();

            for (char c : sets[i]){
                for (char cr : elements[c - 'A']){
                    elements[i].insert(cr);
                }
            }

            if (elements[i].size() != s) flag = true;
        }

        if (!flag) break;
    }

    for (int i = 0; i < 26; i++){
        if (used[i]){
            printf("%c = {", i + 'A');
            bool f = false;
            for (char c : elements[i]){
                if (f) printf(",");
                f = true;

                printf("%c", c);
            }
            printf("}\n");
        }
    }
}
