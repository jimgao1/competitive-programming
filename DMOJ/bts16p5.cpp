#include <bits/stdc++.h>

#define MAXN 10010

using namespace std;

int N, C, K, value[MAXN], svalue[MAXN], sweight[MAXN], dp[MAXN];
vector<pair<int, int>> adjList[MAXN];

void dfs(int cur, int parent){
    svalue[cur] = value[cur];

    for (pair<int, int> i : adjList[cur]){
        if (i.first != parent){
            dfs(i.first, cur);

            svalue[cur] += svalue[i.first];
            sweight[cur] += sweight[i.first] + i.second;
            dp[cur] += dp[i.first];

            if (sweight[i.first] + i.second <= K && svalue[i.first] >= C){
                dp[cur] += 1;
            }
        }
    }

}

int main(){
    cin >> N >> C >> K;
    for (int i = 0; i < N; i++) cin >> value[i];

    for (int i = 0, a, b, w; i < N - 1; i++){
        cin >> a >> b >> w;
        adjList[a - 1].push_back({b - 1, w});
        adjList[b - 1].push_back({a - 1, w});
    }

    dfs(0, -1);
    
    cout << dp[0] << endl;
}
