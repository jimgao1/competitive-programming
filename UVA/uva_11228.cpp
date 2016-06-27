
#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

struct edge{
    int a, b;
    double w;
};

bool cmp(edge a, edge b) { return a.w < b.w; }

int T, N, R, city[MAXN], state[MAXN];
vector<pair<int, int>> points;
vector<edge> e;

double dist(pair<int, int> pa, pair<int, int> pb){
    double dx = pa.first - pb.first, dy = pa.second - pb.second;
    return sqrt(dx * dx + dy * dy);
}

void init(int* dset) {
    for (int i = 0; i < MAXN; i++)
        dset[i] = i;
}

int ufind(int* dset, int n){
    while(n != dset[n])
        n = dset[n];
    return n;
}

void umerge(int* dset, int a, int b){
    int ra = ufind(dset, a), rb = ufind(dset, b);
    dset[ra] = rb;
}

int main(){
    cin >> T;
    for (int cc = 0; cc < T; cc++) {
        init(state);
        points.clear();
        e.clear();

        cin >> N >> R;
        for (int i = 0, a, b; i < N; i++) {
            cin >> a >> b;
            points.push_back({a, b});
        }

        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                if (dist(points[i], points[j]) <= R) {
                    umerge(state, i, j);
                }

                e.push_back({i, j, dist(points[i], points[j])});
            }
        }

        int nstates = 0;
        double ccity = 0, cstate = 0;

        for (int i = 0; i < N; i++){
            if (i == ufind(state, i)) nstates++;
        }

        sort(e.begin(), e.end(), cmp);

        for (int i = 0; i < N; i++){
            int cs = ufind(state, i);
            if (state[i] == i){
                init(city);
                vector<edge> te;
                vector<int> nodes;

                for (int j = 0; j < N; j++){
                    if (ufind(state, j) == cs)
                        nodes.push_back(j);
                }

                for (int j = 0; j < nodes.size(); j++){
                    for (int k = j + 1; k < nodes.size(); k++){
                        te.push_back({nodes[j], nodes[k],
                                      dist(points[nodes[j]], points[nodes[k]])});
                    }
                }

                sort(te.begin(), te.end(), cmp);

                for (edge t : te){
                    if (ufind(city, t.a) != ufind(city, t.b)){
                        ccity += t.w;
                        umerge(city, t.a, t.b);
                    }
                }
            }
        }


        for (edge t : e){
            if (ufind(state, t.a) != ufind(state, t.b)){
                cstate += t.w;
                umerge(state, t.a, t.b);
            }
        }

        printf("Case #%d: %d %d %d\n", cc + 1, nstates, (int)round(ccity), (int)round(cstate));
    }
}
