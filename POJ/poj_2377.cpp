
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

struct edge{
    int src, tar, weight;
    edge(int a, int b, int c){
        src = a, tar = b, weight = c;
    }
};

bool comp(edge a, edge b){
    return a.weight > b.weight;
}

int N, M, ex = 0, dset[1001], dsize[1001];
ll ans = 0;

vector<edge> e;

void build(){
    for (int i = 0; i < N; i++)
        dset[i] = i, dsize[i] = 1;
}

int ufind(int n){
    int root = n;

    while(root != dset[root]) root = dset[root];

    while(root != n){
        int temp = dset[n];
        dset[n] = root;
        n = temp;
    }

    return root;
}

void umerge(int a, int b){
    int ra = ufind(a), rb = ufind(b);

    if (ra == rb) return;

    if (dsize[ra] > dsize[rb]){
        dset[rb] = ra;
        dsize[ra] += dsize[rb];
    } else {
        dset[ra] = rb;
        dsize[rb] += dsize[ra];
    }
}

int main(){
    scanf("%d%d", &N, &M);
    build();

    for(int i = 0, src, tar, weight; i < M; i++){
        scanf("%d%d%d", &src, &tar, &weight);
        e.push_back(edge(src - 1, tar - 1, weight));
    }

    sort(e.begin(), e.end(), comp);

    for (int i = 0; i < e.size(); i++){
        int src = e[i].src, tar = e[i].tar, weight = e[i].weight;

        if (ufind(src) != ufind(tar)){
            ans += weight;
            umerge(src, tar);
            ex++;
        }
    }

    printf("%d\n", (ex == N - 1) ? ans : -1);
}
