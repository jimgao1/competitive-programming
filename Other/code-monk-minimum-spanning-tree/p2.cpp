
#include <bits/stdc++.h>

using namespace std;

struct edge{
    int src, tar, weight;
    edge(int a, int b, int c) { src = a, tar = b, weight = c; }
};

int T, N, M, tsum = 0, ecnt = 0, dset[5001];
vector<edge> e;

bool comp(edge a, edge b) { return a.weight > b.weight; }

void ubuild(){ for (int i = 0; i < N; i++) dset[i] = i; }

int ufind(int n){
    while(n != dset[n]) n = dset[n];
    return n;
}

void umerge(int a, int b){
    int ra = ufind(a), rb = ufind(b);
    if (ra == rb) return;

    dset[rb] = ra;
}

int main(){
    freopen("input.txt", "r", stdin);

    scanf("%d", &T);
    while(T--){
        tsum = 0, ecnt = 0;
        e.clear();

        scanf("%d%d", &N, &M);
        for (int i = 0, src, tar, weight; i < M; i++){
            scanf("%d%d%d", &src, &tar, &weight);
            e.push_back(edge(src - 1, tar - 1, weight));
        }
        sort(e.begin(), e.end(), comp);

        ubuild();

        for (int i = 0; i < e.size(); i++){
            if (ecnt == N - 1) break;

            int src = e[i].src, tar = e[i].tar, w = e[i].weight;

            if (ufind(src) != ufind(tar)){
                tsum += w;
                umerge(src, tar);
                ecnt++;
            }
        }

        printf("%d\n", tsum);
    }
}
