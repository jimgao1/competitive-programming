#include <bits/stdc++.h>

#define MAXN 501
#define pii pair<int, int>

using namespace std;

int N, Q, rad[MAXN];
bool visited[MAXN];
vector<pair<int, int>> points;

double dist(int i, int j){
    double dx = points[i].first - points[j].first;
    double dy = points[i].second - points[j].second;
    return sqrt(dx * dx + dy * dy);
}

bool test(int src, int tar){
    memset(visited, 0, sizeof visited);
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if (cur == tar) return true;

        if (visited[cur]) continue;
        visited[cur] = true;

        for (int i = 0; i < N; i++){
            if (dist(cur, i) <= rad[cur]){
                q.push(i);
            }
        }
    }

    return false;
}

int main(){
    cin >> N >> Q;
    for (int i = 0, x, y; i < N; i++){
        cin >> x >> y >> rad[i];
        points.push_back({x, y});
    }

    for (int i = 0, a, b; i < Q; i++){
        cin >> a >> b;
        cout << (test(a - 1, b - 1) ? "YES" : "NO") << endl;
    }
}
