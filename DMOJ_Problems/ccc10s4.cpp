
#include <bits/stdc++.h>

using namespace std;

struct edge{
    int src, tar, weight;
};

int N, mfence = 0, dset[110], weight[1001][1001];
bool visited[101];
vector<int> fence[1001][1001], adjList[101];
vector<edge> e;

void dfs(int cur){
    if (visited[cur]) return;
    visited[cur] = true;
    for (int i : adjList[cur])
        if (!visited[i])
            dfs(i);
}

bool cmp(edge a, edge b){
    return a.weight < b.weight;
}

void build(){
    for (int i = 0; i < 102; i++){
        dset[i] = i;
    }
}

int ufind(int n){
    while(n != dset[n])
        n = dset[n];
    return n;
}

void umerge(int a, int b){
    int ra = ufind(a), rb = ufind(b);
    if (ra == rb) return;
    dset[ra] = rb;
}

int main(){
    freopen("input.txt", "r", stdin);

    scanf("%d", &N);
    for (int i = 0, cnt; i < N; i++){
        vector<int> points;

        scanf("%d", &cnt);
        for (int j = 0, p; j < cnt; j++){
            scanf("%d", &p);
            mfence = max(mfence, p);
            points.push_back(p);
        }

        for (int j = 0, w; j < cnt; j++){
            scanf("%d", &w);

            int pa = points[j], pb = points[(j + 1) % cnt];
            fence[pa][pb].push_back(i);
            fence[pb][pa].push_back(i);
            weight[pa][pb] = w;
            weight[pb][pa] = w;
        }
    }

    for (int i = 0; i <= mfence; i++){
        for (int j = i + 1; j <= mfence; j++){
            if (fence[i][j].size() == 1){
                e.push_back({fence[i][j][0], N, weight[i][j]});
            } else if (fence[i][j].size() == 2){
                adjList[fence[i][j][0]].push_back(fence[i][j][1]);
                adjList[fence[i][j][1]].push_back(fence[i][j][0]);
                e.push_back({fence[i][j][0], fence[i][j][1], weight[i][j]});
            }
        }
    }

    dfs(0);
    bool flag = true;
    for (int i = 0; i < N; i++){
        if (!visited[i]) flag = false;
    }

    build();
    sort(e.begin(), e.end(), cmp);

    int cnt = 0, tmp = 0, ans = 0;
    for (edge i : e){
        if (cnt == N + 1) break;
        if (ufind(i.src) != ufind(i.tar)){
            ans += i.weight;
            cnt++;
            umerge(i.src, i.tar);

            if (i.src == N || i.tar == N)
                tmp = i.weight;
        }
    }

    if (flag)
        printf("%d\n", ans - tmp);
    else
        printf("%d\n", ans);

}
