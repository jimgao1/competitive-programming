
#include <bits/stdc++.h>

#define MAXN 300000
#define LOGMAXN 19

using namespace std;

int N;
int pa[MAXN][LOGMAXN];
int depth[MAXN], parent[MAXN], nref[MAXN], ncnt[MAXN];

vector<pair<int, int>> queries;
vector<int> adjList[MAXN];

void dfs(int cur, int d, int prev){
    depth[cur] = d;
    pa[cur][0] = prev;
    for(auto e : adjList[cur]){
        if(e != prev)
            dfs(e, d+1, cur);
    }
}

void build(){
    dfs(0, 0, -1);
    for(int i = 1; i < LOGMAXN; i++){
        for(int j = 0; j < N; j++){
            if(pa[j][i-1] != -1)
                pa[j][i] = pa[pa[j][i-1]][i-1];
        }
    }
}

int getNode(int node){
    while(node != nref[node])
        node = nref[node];

    return node;
}

int lca(int i, int j){
    if(depth[i] < depth[j])
        swap(i, j);

    for(int k = LOGMAXN-1; k >= 0; k--){
        if(pa[i][k] != -1 && depth[pa[i][k]] >= depth[j])
            i = pa[i][k];
    }

    if(i == j)
        return i;

    for(int k = LOGMAXN-1; k >= 0; k--){
        if(pa[i][k] != -1 && pa[j][k] != -1 && pa[i][k] != pa[j][k]){
            i = pa[i][k];
            j = pa[j][k];
        }
    }

    return pa[i][0];
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    nref[0] = 0;
    parent[0] = 0;

    for (int i = 1; i <= N; i++){
        char cmd; int v, w;
        cin >> cmd;

        if (cmd == 'a'){
            cin >> v;
            v = getNode(v);

            parent[i] = v;
            nref[i] = i;
            ncnt[i] = ncnt[v] + 1;
        } else if (cmd == 'b'){
            cin >> v;
            v = getNode(v);

            queries.push_back({-1, v});
            parent[i] = parent[parent[v]];
            nref[i] = parent[v];
            ncnt[getNode(nref[i])] ++;
        } else if (cmd == 'c'){
            cin >> v >> w;
            //v = getNode(v), w = getNode(w);

            parent[i] = parent[v];
            nref[i] = v;

            queries.push_back({i, w});
        }
    }

    for (int i = 1; i <= N; i++){
        if (getNode(i) != i) continue;
        parent[i] = getNode(parent[i]);
        adjList[parent[i]].push_back(i);
    }

    build();

    for (auto i : queries){

        if (i.first == -1){
            cout << i.second << "\n";
        } else {
            cout << depth[lca(getNode(i.first), getNode(i.second))] << "\n";
        }
    }
}
