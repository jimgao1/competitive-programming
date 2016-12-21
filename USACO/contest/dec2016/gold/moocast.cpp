
#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

struct edge{
    int src, tar;
    int dist;
    edge(int a, int b, int c){
        src = a, tar = b, dist = c;
    }
};

int N, dset[MAXN];
vector<pair<int, int>> points;
vector<edge> e;

void uinit(){
    for (int i = 0; i < MAXN; i++) dset[i] = i;
}

int ufind(int n){
    while(n != dset[n]) n = dset[n];
    return n;
}

void umerge(int a, int b){
    dset[ufind(a)] = ufind(b);
}

bool cmp(edge a, edge b){
    return a.dist < b.dist;
}

int dist(pair<int, int> a, pair<int, int> b){
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return dx * dx + dy * dy;
}

int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    uinit();
    cin >> N;
    for (int i = 0, x, y; i < N; i++){
        cin >> x >> y;
        points.push_back({x, y});
    }

    for (int i = 0; i < N; i++){
        for (int j = i + 1; j < N; j++){
            e.push_back(edge(i, j, dist(points[i], points[j])));
        }
    }
    sort(e.begin(), e.end(), cmp);

    int ans = 0;
    for (edge cur : e){
        if (ufind(cur.src) != ufind(cur.tar)){
            ans = max(ans, cur.dist);
            umerge(cur.src, cur.tar);
        }
    }

    cout << ans << endl;
}
