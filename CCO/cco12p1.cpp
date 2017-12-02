
#include <bits/stdc++.h>

#define MAXN

using namespace std;

int W, D, V;
bool visited[5000001][6];
vector<int> digits;
queue<pair<int, int>> q;

bool test(int tar){
    while(!q.empty()) q.pop();
    memset(visited, 0, sizeof visited);

    for (int i : digits)
        q.push({i, 0});

    while(!q.empty()){
        int cur = q.front().first, st = q.front().second;
        q.pop();

        if (visited[cur][st]) continue;
        visited[cur][st] = true;

        if (st == W && cur == tar){
            return true;
        }

        if (st >= W) continue;

        for (int i : digits){
            q.push({cur * i, st + 1});
            q.push({cur + i, st + 1});
        }
    }

    return false;
}

int main(){
    cin >> W >> D;
    for (int i = 0, x; i < D; i++){
        cin >> x;
        digits.push_back(x);
    }
    cin >> V;

    for (int i = 0, x; i < V; i++){
        cin >> x;
        cout << (test(x) ? "Y" : "N") << endl;
    }
}

