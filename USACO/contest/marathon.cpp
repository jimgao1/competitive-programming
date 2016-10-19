
#include <bits/stdc++.h>

#define MAXN 509

using namespace std;

int N, K, dp[MAXN][MAXN];
bool ext[MAXN][MAXN];
vector<pair<int, int>> locs;
queue<pair<int, int>> q;

int dist(int i, int j){
    return abs(locs[i].first - locs[j].first)
            + abs(locs[i].second - locs[j].second);
}

int main(){
    freopen("marathon.in", "r", stdin);
    freopen("marathon.out", "w", stdout);

    cin >> N >> K;
    for (int i = 0, x, y; i < N; i++){
        cin >> x >> y;
        locs.push_back({x, y});
    }

    memset(dp, 0x3f, sizeof dp);

    q.push({0, 0});
    ext[0][0] = true;
    dp[0][0] = 0;

    while(!q.empty()){
        int cur = q.front().first, skipped = q.front().second;
        q.pop();

        ext[cur][skipped] = false;
        if (cur == N - 1) continue;

        for (int i = 0; skipped + i <= K; i++){
            if (cur + i + 1 >= N) break;

            int dest = cur + i + 1;
            int alt = dp[cur][skipped] + dist(cur, dest);

            if (alt < dp[dest][skipped + i]){
                dp[dest][skipped + i] = alt;

                if (!ext[dest][skipped + i]){
                    ext[dest][skipped + i] = true;
                    q.push({dest, skipped + i});
                }
            }
        }
    }

    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= K; i++){
        ans = min(ans, dp[N - 1][i]);
    }

    cout << ans << endl;
}

