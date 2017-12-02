#include <bits/stdc++.h>

using namespace std;

int N, K, B, cnt = 0, order[50001], depth[50001];
bool visited[50001];

vector<pair<int, int>> shit;
vector<int> adjList[50001];

void dfs(int cur){
    //if (visited[cur]) return;

    for (int i : adjList[cur]){
        if (visited[i]) continue;
        visited[i] = true;
        depth[i] = depth[cur] + 1;
        dfs(i);

        order[i] = cnt--;
    }
}

bool cmp(pair<int, int> a, pair<int, int> b){
    if (a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}

int main(){
    scanf("%d", &N);
    cnt = N;

    for (int i = 1, x; i <= N; i++){
        scanf("%d", &x);
        for (int j = 0, k; j < x; j++){
            scanf("%d", &k);
            adjList[i].push_back(k);
        }
    }
    depth[1] = 1, order[1] = 1;
    dfs(1);

    for (int i = 1; i <= N; i++){
        shit.push_back({depth[i], order[i]});
    }
    sort(shit.begin(), shit.end(), cmp);

    for (auto i : shit)
        cout << i.second << " ";
    cout << endl;
}
