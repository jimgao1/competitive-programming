#include <bits/stdc++.h>

#define MAXN 100001

using namespace std;

int N, M, cnt[MAXN], dist[MAXN], ans = 0;
bool p[MAXN];
vector<int> pho, dd;
vector<int> adjList[MAXN];

queue<pair<int, int>> q;

void mark(int cur, int last){
    for (int i : adjList[cur]){
        if (i != last){
            mark(i, cur);
            cnt[cur] += cnt[i];
        }

    }
}

void dfs2(int cur, int last){
    for (int i : adjList[cur]){
        if (i != last && cnt[i] > 0){
            ans += 2;
            dfs2(i, cur);
        }
    }
}

void calcDist(int src){
    memset(dist, 0x3f, sizeof dist);

    q.push({src, 0});
    while(!q.empty()){
        int cur = q.front().first, st = q.front().second;
        q.pop();

        if (cnt[cur] == 0) continue;

        if (dist[cur] <= st) continue;
        dist[cur] = st;

        for (int i : adjList[cur]){
            if (dist[cur] + 1 < dist[i]){
                q.push({i, st + 1});
            }
        }
    }
}

int main(){

    scanf("%d%d", &N, &M);
    for (int i = 0, x; i < M; i++){
        scanf("%d", &x);
        cnt[x] = 1;
        pho.push_back(x);
    }

    for (int i = 0, a, b; i < N - 1; i++){
        scanf("%d%d", &a, &b);
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    mark(pho[0], -1);
    dfs2(pho[0], -1);

    memset(dist, 0x3f, sizeof dist);
    calcDist(pho[0]);

    int maxDist = 0, id = -1;
    for (int i = 0; i < N; i++){
        if (dist[i] > maxDist && dist[i] < 0x3f3f3f3f){
            maxDist = dist[i];
            id = i;
        }
    }

    memset(cnt, 0, sizeof cnt);
    for (int i : pho) cnt[i] = 1;
    mark(id, -1);
    memset(dist, 0x3f, sizeof dist);
    calcDist(id);

    maxDist = 0;
    for (int i = 0; i < N; i++){
        if (dist[i] < 0x3f3f3f3f)
            maxDist = max(maxDist, dist[i]);
    }

    printf("%d\n", ans - maxDist);
}
