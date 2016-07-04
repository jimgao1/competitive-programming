
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define MAXN 2001

using namespace std;

struct edge{
    int src, tar, weight;
    edge(){}
    edge(int _, int __, int ___){
        src = _, tar = __, weight = ___;
    }
};
bool cmp(edge a, edge b){ return a.weight < b.weight; }

int N, M, dset[MAXN];
vector<edge> e;
vector<int> used;

void init(){
    for (int i = 0; i < MAXN; i++) dset[i] = i;
}

int ufind(int i){
    while(i != dset[i]) i = dset[i];
    return i;
}

void umerge(int a, int b){
    dset[ufind(a)] = ufind(b);
}

int main(){
    while(true) {
        e.clear();
        used.clear();

        cin >> N >> M;
        if (N == 0 && M == 0) break;
        for (int i = 0, a, b, w; i < M; i++) {
            cin >> a >> b >> w;
            e.push_back(edge(a, b, w));
        }

        init();
        sort(e.begin(), e.end(), cmp);

        for (edge ce : e) {
            if (ufind(ce.src) != ufind(ce.tar)) {
                umerge(ce.src, ce.tar);
            } else {
                used.push_back(ce.weight);
            }
        }

        if (used.size() == 0) {
            cout << "forest";

        } else {
            for (int i = 0; i < used.size(); i++) {
                if (i != 0) cout << " ";
                cout << used[i];
            }

        }
        cout << endl;
    }
}
