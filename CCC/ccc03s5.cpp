
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define MAXN 10001

using namespace std;

struct edge{
    int src, tar, weight;
    edge(int _, int __, int ___){
        src = _, tar = __, weight = ___;
    }
};

bool cmp(edge a, edge b) { return a.weight > b.weight; }

int N, M, D, dset[MAXN], wid[MAXN];
vector<edge> e;
vector<pair<int, int>> adjList[MAXN];
queue<pair<int, int>> q;

void init(){
    for (int i = 0; i < MAXN; i++)
        dset[i] = i;
}

int ufind(int n){
    while(n != dset[n])
        n = dset[n];
    return n;
}

void umerge(int a, int b){
    dset[ufind(a)] = ufind(b);
}

int main(){
    scanf("%d%d%d", &N, &M, &D);
    for (int i = 0, a, b, c; i < M; i++){
        scanf("%d%d%d", &a, &b, &c);
        e.push_back(edge(a - 1, b - 1, c));
    }

    sort(e.begin(), e.end(), cmp);
    init();

    for (edge cur : e){
        if (ufind(cur.src) != ufind(cur.tar)){
            umerge(cur.src, cur.tar);
            adjList[cur.src].push_back({cur.tar, cur.weight});
            adjList[cur.tar].push_back({cur.src, cur.weight});
        }
    }

    q.push({0, INF});
    while(!q.empty()){
        int cur = q.front().first, wd = q.front().second;
        q.pop();

        wid[cur] = max(wid[cur], wd);

        for (pair<int, int> n : adjList[cur]){
            if (wid[n.first] < min(wd, n.second))
                q.push({n.first, min(wd, n.second)});
        }
    }

    int ans = INF;

    for (int i = 0, x; i < D; i++){
        scanf("%d", &x);
        ans = min(ans, wid[x - 1]);
    }

    printf("%d\n", ans);

}
