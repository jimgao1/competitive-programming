
#include <bits/stdc++.h>

#define ll long long
#define MAXN 1000001

using namespace std;

int N;
ll sum[MAXN], level[MAXN];
vector<int> adjList[MAXN];
vector<pair<pair<int, int>, int>> e;

void dfs(int cur, int pre){
    sum[cur] = 1;
    for (int i : adjList[cur]){
        if (i != pre){
            level[i] = level[cur] + 1;
            dfs(i, cur);
            sum[cur] += sum[i];
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0, a, b, c; i < N - 1; i++){
        cin >> a >> b >> c;
        a--, b--;
        e.push_back({{a, b}, c});
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    dfs(0, -1);

    ll ans = 0;
    for (pair<pair<int, int>, int> cur : e){
        int a = cur.first.first, b = cur.first.second;
        int w = cur.second;

        if (level[a] > level[b]){
            ans += abs(sum[a] - (N - sum[a])) * w;
        } else {
            ans += abs(sum[b] - (N - sum[b])) * w;
        }
    }

    cout << ans << "\n";
}
