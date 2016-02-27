#include <bits/stdc++.h>

#define MAXN 801
#define INF 0x3f3f3f3f

using namespace std;

struct edge{
    int src, tar;
    double weight;
    edge(int a, int b, double c){
        src = a, tar = b, weight = c;
    }
};

bool cmp(edge a, edge b) { return a.weight < b.weight; }

int N, M, dset[MAXN];
double total = 0;
vector<pair<int, int>> points, used;
vector<edge> e;

void init(){ for (int i = 0; i < MAXN; i++) dset[i] = i; }
int ufind(int n) { while (n != dset[n]) n = dset[n]; return n; }
void umerge(int a, int b) { dset[ufind(a)] = dset[ufind(b)]; }

int main(){
    scanf("%d", &N);
    for (int i = 0, x, y; i < N; i++){
        scanf("%d%d", &x, &y);
        points.push_back({x, y});
    }

    init();

    for (int i = 0; i < N; i++){
        for (int j = i + 1; j < N; j++){
            double dx = points[i].first - points[j].first ;
            double dy = points[i].second - points[j].second;

            e.push_back(edge(i, j, sqrt(dx * dx + dy * dy)));
        }
    }

    scanf("%d", &M);
    for (int i = 0, a, b; i < M; i++){
        scanf("%d%d", &a, &b);
        umerge(a - 1, b - 1);
    }

    sort(e.begin(), e.end(), cmp);

    for (edge cur : e){
        if (ufind(cur.src) != ufind(cur.tar)){
            used.push_back({cur.src + 1, cur.tar + 1});
            total += cur.weight;

            umerge(cur.src, cur.tar);
        }
    }

    printf("%.2f\n", total);
    for (pair<int, int> u : used) printf("%d %d\n", u.first, u.second);
}
