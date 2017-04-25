
#include <bits/stdc++.h>

#define MAXN 100010

using namespace std;

int N, M;
vector<int> adjList[MAXN];

int idx = 0, parent[MAXN], low[MAXN], order[MAXN];
bool ap[MAXN], visited[MAXN];

void dfs(int cur){
    visited[cur] = 1;

    int child = 0;
    order[cur] = low[cur] = ++idx;

    for (int i : adjList[cur]){
        if (!visited[i]){
            child++;
            parent[i] = cur;

            dfs(i);
            low[cur] = min(low[cur], low[i]);

            if (parent[cur] == -1){
                //Case 1: If the current node is the root
                if (child >= 2) ap[cur] = 1;
            } else {
                //Case 2: Low[Child] > Order[Cur]
                if (low[i] >= order[cur]) ap[cur] = 1;
            }
        } else if (i != parent[cur]){
            low[cur] = min(low[cur], order[i]);
        }
    }
}

void findAP(){
    memset(parent, -1, sizeof parent);

    for (int i = 0; i < N; i++){
        if (!visited[i])
            dfs(i);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0, a, b; i < M; i++){
        cin >> a >> b;
        a--, b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    findAP();

    vector<int> APs;
    for (int i = 0; i < N; i++) if (ap[i]) APs.push_back(i + 1);

    printf("%d\n", APs.size());
    for (int i : APs)
        printf("%d\n", i);
}
