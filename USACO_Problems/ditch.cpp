/*
ID: jim.yub1
LANG: C++11
TASK: ditch
*/

#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define ll long long

using namespace std;

int N, M, matrix[210][210], pre[210];
bool visited[210];

void update_residual_network(int node, int val){
    while(pre[node] != -1){
        matrix[pre[node]][node] -= val;
        matrix[node][pre[node]] += val;

        node = pre[node];
    }
}

ll bfs(int src, int tar){
    memset(visited, 0, sizeof visited);
    memset(pre, -1, sizeof pre);

    visited[src] = true;
    ll minFlow = INF * 1000;

    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int current = q.front();
        q.pop();

        if (current == tar) break;

        for (int i = 0; i < N; i++){
            if (!visited[i] && matrix[current][i] != 0){
                q.push(i);
                minFlow = min(minFlow, (ll)matrix[current][i]);
                pre[i] = current;
                visited[i] = true;
            }
        }
    }

    if (pre[tar] == -1) return 0;
    return minFlow;
}

int main(){
    freopen("ditch.in", "r", stdin);
    freopen("ditch.out", "w", stdout);

    memset(matrix, 0, sizeof matrix);

    scanf("%d%d", &M, &N);
    for (int i = 0, a, b, c; i < M; i++){
        scanf("%d%d%d", &a, &b, &c);
        matrix[a - 1][b - 1] += c;
    }

    ll maxFlow = 0, newFlow = 0;
    while(true){
        newFlow = bfs(0, N - 1);
        if (newFlow == 0) break;

        update_residual_network(N - 1, newFlow);
        maxFlow += newFlow;

    }

    printf("%d\n", maxFlow);
}
