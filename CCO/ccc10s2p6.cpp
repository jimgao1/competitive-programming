
#include <bits/stdc++.h>

using namespace std;

int N, cycle[256];
string str;
bool visited[256];
char nxt[256], final[256];

void mark(char src){
    memset(visited, 0, sizeof visited);

    int cnt = 0;
    char cur = src;
    while(true){
        if (visited[cur]){
            if (cur == src){
                cycle[src] = cnt;
            }
            return;
        }

        cnt++;
        visited[cur] = true;
        cur = nxt[cur];
    }
}

void check(char src){
    int st = N;
    char cur = src;

    while(st > 0){
        st--;
        cur = nxt[cur];

        if (cycle[cur] != -1){
            st = st % cycle[cur];
        }
    }

    final[src] = cur;
}

int main(){
    for (char c = 'A'; c <= 'Z'; c++){
        cin >> nxt[c];
    }
    cin >> nxt['_'] >> N >> str;

    memset(cycle, -1, sizeof cycle);
    for (int i = 0; i < 26; i++) mark('A' + i);
    mark('_');

    for (int i = 0; i < 26; i++) check('A' + i);
    check('_');

    for (int i = 0; i < str.size(); i++){
        cout << final[str[i]];
    }
    cout << endl;
}
