
#include <bits/stdc++.h>

#define MAXN 101
#define INF 0x3f3f3f3f

using namespace std;

int D, N, dp[6001];
bool visited[6001];

vector<int> stroke;
queue<int> q;

int main(){
    cin >> D >> N;
    for (int i = 0, x; i < N; i++){
        cin >> x;
        stroke.push_back(x);
    }

    memset(dp, 0x3f, sizeof dp);

    q.push(0);
    dp[0] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for (int n : stroke){
            if (cur + n > D) continue;
            if (dp[cur + n] > dp[cur] + 1){
                dp[cur + n] = dp[cur] + 1;
                q.push(cur + n);
            }
        }
    }

    if (dp[D] == INF)
        printf("Roberta acknowledges defeat.\n");
    else
        printf("Roberta wins in %d strokes.\n", dp[D]);
}

