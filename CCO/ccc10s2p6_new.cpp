#include <bits/stdc++.h>

#define ll long long

using namespace std;

int nxt[30], cycle[30];
ll N;
bool visited[30];
string str;

int main(){
    for (int i = 0; i < 27; i++){
        char c;
        cin >> c;

        if (c == '_')
            nxt[i] = 26;
        else
            nxt[i] = c - 'A';
    }

    for (int i = 0; i < 27; i++){
        memset(visited, 0, sizeof visited);
        int cur = i;
        while(true){
            if (visited[cur]) break;
            visited[cur] = true;
            cur = nxt[cur];
            cycle[i] ++;
        }

        //printf("i = %d, cycle = %d\n", i, cycle[i]);
    }

    cin >> N >> str;

    for (char c : str){
        int id = (c == '_' ? 26 : c - 'A');
        int x = N % cycle[id];
        for (int i = 0; i < x; i++){
            id = nxt[id];
        }
        cout << (id == 26 ? '_' : (char)(id + 'A'));
    }

    cout << endl;
}
