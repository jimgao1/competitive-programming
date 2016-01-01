#include <bits/stdc++.h>

#define INF (1 << 30)

using namespace std;

int N, M, T, Q, dist[1001][1001];
vector<int> adjList[1001];

queue<pair<int, int>> q;

//fucking dmoj wont accept my solution
void bfs(int src){
    while(!q.empty()) q.pop();

    for (int i = 0; i < N; i++) dist[src][i] = INF;
    dist[src][src] = 0;

    q.push({src, 0});
    while(!q.empty()){
        int cur = q.front().first, cost = q.front().second;
        q.pop();

        for (int i : adjList[cur]){
            if (dist[src][i] > dist[src][cur] + 1){
                dist[src][i] = dist[src][cur] + 1;
                q.push({i, dist[src][i]});
            }
        }
    }
}

int main(){
    scanf("%d%d%d", &N, &M, &T);

    for (int i = 0, a, b; i < M; i++){
        scanf("%d%d", &a, &b);
        adjList[a - 1].push_back(b - 1);
    }

    for (int i = 0; i < N; i++)
        bfs(i);

    scanf("%d", &Q);
    for (int i = 0, a, b; i < Q; i++){
        scanf("%d%d", &a, &b);
        if (dist[a - 1][b - 1] >= INF)
            printf("Not enough hallways! \n");
        else
            printf("%d\n", dist[a - 1][b - 1] * T);
    }


}
