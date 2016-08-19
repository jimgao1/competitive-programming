#include <bits/stdc++.h>

#define MAXN 1010

using namespace std;

int T, N, M, cnt = 0;
bool visited[MAXN], ans[MAXN], desc[MAXN];
map<string, int> dict;
vector<int> parent[MAXN], child[MAXN];

void markAns(int id){
    if (ans[id]) return;
    ans[id] = true;
    for (int x : parent[id]) markAns(x);
}

void markDesc(int id){
    if (desc[id]) return;
    desc[id] = true;
    for (int x : child[id]) markDesc(x);
}


bool redneck(int id) {

    if (visited[id]) return false;
    visited[id] = true;

    memset(ans, 0, sizeof ans);
    memset(desc, 0, sizeof desc);
    markAns(id);
    markDesc(id);

    for (int i = 0; i < N; i++){
        if (i != id && ans[i] && desc[i]) return true;
    }

    for (int n : parent[id])

        if (redneck(n)) {
            return true;
        }

    for (int n : child[id])
        if (redneck(n)) {
            return true;
        }

    return false;
}


int main() {
    cin >> T;
    while (T--) {
        cnt = 0;
        dict.clear();
        memset(visited, 0, sizeof visited);
        for (int i = 0; i < MAXN; i++){
            parent[i].clear();
            child[i].clear();
        }

        cin >> N;

        for (int i = 0; i < N; i++) {
            string name;
            cin >> name;

            if (dict.find(name) == dict.end()) dict[name] = cnt++;

            cin >> M;
            for (int j = 0; j < M; j++) {
                string nxt;
                cin >> nxt;

                if (dict.find(nxt) == dict.end()) dict[nxt] = cnt++;

                parent[dict[name]].push_back(dict[nxt]);
                child[dict[nxt]].push_back(dict[name]);
            }
        }

        cout << (redneck(dict["Jim-Bob"]) ? "Redneck" : "Not a redneck") << endl;
    }
}
