
#include <bits/stdc++.h>

#define ll long long
#define MAXN 19

using namespace std;

inline bool getBit(int n, int idx) { return n & (1 << idx); }
inline int setBit(int n, int idx) { return n | (1 << idx); }
inline int clearBit(int n, int idx) { return n & ~(1 << idx); }

int N, M;
ll dp[MAXN][(1 << MAXN)];
vector<pair<int, int>> adjList[MAXN];
queue<pair<int, int>> q;

ll max(ll a, ll b) { return (a > b ? a : b); }

int main(){

    scanf("%d%d", &N, &M);
    for (int i = 0, src, tar, weight; i < M; i++){
        scanf("%d%d%d", &src, &tar, &weight);
        adjList[src].push_back({tar, weight});
    }

    q.push({0, 1});
    while(!q.empty()){
        int cur = q.front().first, visited = q.front().second;
        q.pop();

        for (pair<int, int> e : adjList[cur]){
            if (!getBit(visited, e.first)){
                int nv = setBit(visited, e.first);

                if (dp[e.first][nv] < dp[cur][visited] + e.second){
                    dp[e.first][nv] = dp[cur][visited] + e.second;
                    q.push({e.first, nv});
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < (1 << N); i++){
        ans = max(ans, dp[N - 1][i]);
    }

    printf("%d\n", ans);
}

