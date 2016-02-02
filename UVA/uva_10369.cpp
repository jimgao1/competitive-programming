
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

struct edge{
    int src, tar;
    double weight;

    edge(int a, int b, double c){
        src = a, tar = b, weight = c;
    }

    void print(){
        printf("src = %d\n", src);
        printf("tar = %d\n", tar);
        printf("weight = %.2f\n", weight);

    }
};

bool comp(edge a, edge b){
    return a.weight < b.weight;
}

int T, N, M, dset[501], ncnt = 0;
double minDist = 0;
vector<edge> e, used;
vector<pair<int, int>> outposts;

void disjoint_build(){
    for (int i = 0; i < 501; i++) dset[i] = i;
}

int disjoint_ufind(int n){
    int root = n;
    while(root != dset[root]) root = dset[root];

    return root;
}

void disjoint_umerge(int a, int b){
    int ra = disjoint_ufind(a), rb = disjoint_ufind(b);
    if (ra == rb) return;

    dset[rb] = ra;
}

int main(){

    scanf("%d", &T);
    while(T--){
        e.clear();
        outposts.clear();
        used.clear();
        minDist = 0;
        ncnt = 0;

        disjoint_build();

        scanf("%d%d", &M, &N);

        for (int i = 0, x, y; i < N; i++){
            scanf("%d%d", &x, &y);
            outposts.push_back({x, y});
        }

        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (i == j) continue;

                double dx = abs(outposts[i].first - outposts[j].first);
                double dy = abs(outposts[i].second - outposts[j].second);
                double dist = sqrt(dx * dx + dy * dy);

                e.push_back(edge(i, j, dist));
            }
        }

        sort(e.begin(), e.end(), comp);

        for (int i = 0; i < e.size(); i++){
            if (ncnt == N) break;

            if (disjoint_ufind(e[i].src) != disjoint_ufind(e[i].tar)){
                disjoint_umerge(e[i].src, e[i].tar);
                ncnt++;
                used.push_back(edge(e[i].src, e[i].tar, e[i].weight));
            }
        }

        sort(used.begin(), used.end(), comp);

        for (int i = 0; i < N - M; i++){
            //used[i].print();
            minDist = max(minDist, used[i].weight);
        }

        printf("%.2f\n", minDist);
    }
}
