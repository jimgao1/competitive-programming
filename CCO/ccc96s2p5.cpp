#include <bits/stdc++.h>

#define MAXN 26
#define INF 0x3f3f3f3f

using namespace std;

int N, M, parent[MAXN];

unordered_map<string, bool> ext;
unordered_map<string, int> dict;
unordered_map<int, string> rev;

vector<int> adjList[MAXN];

void dfs(int cur, int prev){
    for (int i : adjList[cur]){
        if (i != prev){
            parent[i] = cur;
            dfs(i, cur);
        }
    }
}

int main(){
    cin >> N >> M;

    ext["Rome"] = true;
    dict["Rome"] = 0;
    rev[0] = "Rome";

    int cnt = 1;

    for (int i = 0; i < N; i++){
        string na, nb;
        cin >> na >> nb;

        if (!ext[na]) {
            ext[na] = true;
            dict[na] = cnt++;
            rev[dict[na]] = na;
        }

        if (!ext[nb]) {
            ext[nb] = true;
            dict[nb] = cnt++;
            rev[dict[nb]] = nb;
        }

        adjList[dict[na]].push_back(dict[nb]);
        adjList[dict[nb]].push_back(dict[na]);
    }

    dfs(dict["Rome"], 0);

    for (int i = 0; i < M; i++){
        string stra, strb;
        cin >> stra >> strb;

        int na = dict[stra], nb = dict[strb];

        vector<string> ta, tb;

        int cur = na;
        while(true){
            ta.push_back(rev[cur]);

            if (cur == 0) break;
            cur = parent[cur];
        }

        cur = nb;
        while(true){
            tb.push_back(rev[cur]);

            if (cur == 0) break;
            cur = parent[cur];
        }

        int ni = INF, nj = INF;

        for (int i = 0; i < ta.size(); i++){
            for (int j = 0; j < tb.size(); j++){
                if (ta[i] == tb[j]){
                    if (i + j < ni + nj){
                        ni = i, nj = j;
                    }
                }
            }
        }

        for (int i = 0; i <= ni; i++) printf("%c", ta[i][0]);
        for (int i = nj - 1; i >= 0; i--) printf("%c", tb[i][0]);

        printf("\n");
    }
}
