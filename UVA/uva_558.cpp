
#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

int T, N, M, dist[MAXN];
vector<pair<pair<int, int>, int>> e;

bool check(int src){
    memset(dist, 0x3f, sizeof dist);
    dist[src] = 0;

    for (int i = 0; i < N; i++){
        for (auto ce : e){
            if (dist[ce.first.first] + ce.second < dist[ce.first.second])
                dist[ce.first.second] = dist[ce.first.first] + ce.second;
        }
    }

    for (auto ce : e){
        if (dist[ce.first.first] + ce.second < dist[ce.first.second])
            return true;
    }

    return false;
}

int main(){
    cin >> T;
    while(T--) {
        e.clear();

        cin >> N >> M;
        for (int i = 0, a, b, w; i < M; i++) {
            cin >> a >> b >> w;
            e.push_back({{a, b}, w});
        }

        bool flag = false;
        for (int i = 0; i < N; i++) {
            if (check(i)) {
                cout << "possible" << endl;
                flag = true;
                break;
            }
        }

        if (!flag) cout << "not possible" << endl;
    }
}
