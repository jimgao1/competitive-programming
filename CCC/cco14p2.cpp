
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

struct edge{
    int src, tar, weight, cost;
    edge(int a) { weight = a; }
    edge(int a, int b, int c, int d){
        src = a, tar = b, weight = c, cost = d;
    }
};

bool cmp(edge a, edge b){
    return a.weight < b.weight;
}

int N, M, A, B, Q, dist1[100001], dist2[100001], sum[100001];
vector<pair<int, int>> adjList1[100001], adjList2[100001], e;
vector<edge> tmp;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

void dijkstraSource(int src){
    while(!q.empty()) q.pop();

    dist1[src] = 0;
    q.push({0, src});

    while(!q.empty()){
        int cur = q.top().second, st = q.top().first;
        q.pop();

        if (dist1[cur] < st) continue;

        for (auto i : adjList1[cur]){
            if (dist1[cur] + i.second < dist1[i.first]){
                dist1[i.first] = dist1[cur] + i.second;
                q.push({dist1[i.first], i.first});
            }
        }
    }
}

void dijkstraTarget(int src){
    while(!q.empty()) q.pop();

    dist2[src] = 0;
    q.push({0, src});

    while(!q.empty()){
        int cur = q.top().second, st = q.top().first;
        q.pop();

        if (dist2[cur] < st) continue;

        for (auto i : adjList2[cur]){
            if (dist2[cur] + i.second < dist2[i.first]){
                dist2[i.first] = dist2[cur] + i.second;
                q.push({dist2[i.first], i.first});
            }
        }
    }
}

int main(){
    scanf("%d%d%d%d", &N, &M, &A, &B);

    for (int i = 0, a, b, c, d; i < M; i++){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        adjList1[a - 1].push_back({b - 1, c});
        adjList2[b - 1].push_back({a - 1, c});
        tmp.push_back(edge(a - 1, b - 1, c, d));
    }

    memset(dist1, 0x3f, sizeof dist1);
    memset(dist2, 0x3f, sizeof dist2);

    dijkstraSource(A - 1);
    dijkstraTarget(B - 1);

    for (edge cur : tmp){
        if (dist1[cur.src] < INF && dist2[cur.tar] < INF){
            e.push_back({dist1[cur.src] + dist2[cur.tar] + cur.weight, cur.cost});
        }
    }

    sort(e.begin(), e.end());

    for (int i = 0; i < e.size(); i++){
        sum[i] = e[i].second;
        if (i > 0) sum[i] += sum[i - 1];
    }

    scanf("%d", &Q);
    for (int i = 0, x; i < Q; i++){
        scanf("%d", &x);

        auto it = upper_bound(e.begin(), e.end(), pair<int, int>({x, INF}));

        printf("%d\n", sum[it - e.begin() - 1]);
    }
}
