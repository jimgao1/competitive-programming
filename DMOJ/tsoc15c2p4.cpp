
#include <bits/stdc++.h>

using namespace std;

int N, M, in[20001], dist[20001], ans = 0;
vector<int> adjList[20001];

queue<pair<int, int>> q;

int main(){
    memset(dist, 0x3f, sizeof dist);

    scanf("%d%d", &N, &M);
    for (int i = 0, a, b; i < M; i++){
        scanf("%d%d", &a, &b);
        adjList[a].push_back(b);
        in[b] ++;
    }

    for (int i = 0; i < N; i++){
        if (in[i] == 0){
            q.push({i, 0});
        }
    }

    while(!q.empty()){
        int cur = q.front().first, st = q.front().second;
        q.pop();

        if (adjList[cur].size() == 0){
            ans++;
            dist[cur] = min(dist[cur], st);
        } else {
            for (int i : adjList[cur]){
                q.push({i, st + 1});
            }
        }
    }

    printf("%d\n", ans);
    for (int i = 0; i < N; i++){
        if (adjList[i].size() == 0){
            printf("%d ", dist[i] + 1);
        }
    }
    printf("\n");
}
