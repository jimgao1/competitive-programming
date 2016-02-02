
#include <bits/stdc++.h>

#define nodeCount 52

using namespace std;

int N;
bool used[26];
set<char> elements[26], sets[26];

int main(){
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
