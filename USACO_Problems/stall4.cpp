/*
ID: jim.yub1
LANG: C++11
TASK: stall4
*/

#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int N, M, matrix[500][500], pre[500];
bool visited[500];

void update_residual_network(int node, int val){
    while(pre[node] != -1){
        matrix[pre[node]][node] -= val;
        matrix[node][pre[node]] += val;

        node = pre[node];
    }
}

int bfs(int src, int tar){
    //printf("bfs: src=%d, tar=%d\n", src, tar);

    memset(visited, 0, sizeof visited);
    memset(pre, -1, sizeof pre);

    visited[src] = true;
    int minFlow = INF;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int current = q.front();
        q.pop();

        if (current == tar) break;

        for (int i = 0; i < 402; i++){
            if (!visited[i] && matrix[current][i] != 0){
                q.push(i);
                minFlow = min(minFlow, (int)matrix[current][i]);
                pre[i] = current;
                visited[i] = true;
            }
        }
    }

    if (pre[tar] == -1) return 0;
    return minFlow;
}

/*
    Cows node: i
    Stall node: i + 200
    Source node: 400
    Target node: 401
*/

int main(){
    freopen("stall4.in", "r", stdin);
    freopen("stall4.out", "w", stdout);

    memset(matrix, 0, sizeof matrix);

    scanf("%d%d", &N, &M);

    for (int i = 0, ncnt; i < N; i++){
        scanf("%d", &ncnt);
        for (int j = 0, stall; j < ncnt; j++){
            scanf("%d", &stall);
            matrix[i][(stall - 1) + 200] = 1;
        }
    }

    for (int i = 0; i < N; i++){
        matrix[400][i] = 1;
    }

    for (int i = 0; i < M; i++){
        matrix[i + 200][401] = 1;
    }

    int maxFlow = 0, newFlow = 0;

    while(true){
        newFlow = bfs(400, 401);
        if (newFlow == 0) break;

        update_residual_network(401, newFlow);
        maxFlow += newFlow;
    }

    printf("%d\n", maxFlow);
}
