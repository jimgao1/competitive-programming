
#include <bits/stdc++.h>

#define MAXN 100001

using namespace std;

struct edge{
    int src, tar, weight;
    edge(int _, int __, int ___){
        src = _, tar = __, weight = ___;
    }
};

bool cmp(edge a, edge b){
    return a.weight < b.weight;
}

int N, K, dset[MAXN];
vector<edge> e;

void uinit(){
    for (int i = 0; i < MAXN; i++)
        dset[i] = i;
}

int ufind(int n){
    while(n != dset[n])
        n = dset[n];
    return n;
}

int mst(){
    int total = 0;
    sort(e.begin(), e.end(), cmp);

    for (edge ce : e){
        int a = ufind(ce.src), b = ufind(ce.tar);
        if (a != b){
            total += ce.weight;
            dset[a] = b;
        }
    }

    return total;
}

int main(){
    uinit();

    scanf("%d%d", &N, &K);
    for (int i = 0, x; i < N - 1; i++){
        scanf("%d", &x);
        e.push_back(edge(i, i + 1, x));
    }
    for (int i = 0; i + K < N; i++){
        e.push_back(edge(i, i + K, 0));
    }

    printf("%d\n", mst());
}

