
#include <bits/stdc++.h>

#define MAXN 1000000
#define LOGMAXN 20

using namespace std;

int pa[MAXN][LOGMAXN];
int depth[MAXN];
vector<int> adjList[MAXN];
int N;

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

}
