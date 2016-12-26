[200~
#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int N, M, src, tar, matrix[MAXN][MAXN], pre[MAXN];
bool visited[MAXN];

void augment(int node, int val){
    while(pre[node] != -1){
        matrix[pre[node]][node] -= val;
        matrix[node][pre[node]] += val;

        node = pre[node];
    }
}

int max_flow(int src, int tar){
    memset(visited, 0, sizeof visited);
    memset(pre, -1, sizeof pre);

    visited[src] = true;
    int minFlow = 1e9;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if (cur == tar) break;

        for (int i = 0; i < N; i++){
            if (!visited[i] && matrix[cur][i] != 0){
                q.push(i);
                minFlow = min(minFlow, (int)matrix[cur][i]);
                pre[i] = cur;
                visited[i] = true;
            }
        }
    }

    if (pre[tar] == -1) return 0;
    return minFlow;
}

int get_flow(int src, int tar){
    int maxFlow = 0, newFlow = 0;
    while(true){
        newFlow = max_flow(src, tar);
        if (newFlow == 0) break;
        augment(tar, newFlow);
        maxFlow += newFlow;
    }
    return maxFlow;
}

int main(){
    int cc = 1;
    while(true) {
        cin >> N;
        if (N == 0) break;
        memset(matrix, 0, sizeof matrix);
        cin >> src >> tar >> M;
        src--, tar--;
        for (int i = 0, a, b, w; i < M; i++) {
            cin >> a >> b >> w;
            a--, b--;
            matrix[a][b] += w;
            matrix[b][a] += w;
        }
        printf("Network %d\nThe bandwidth is %d.\n\n", cc++, get_flow(src, tar));
    }
}[201~
