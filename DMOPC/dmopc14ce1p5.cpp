
#include <bits/stdc++.h>

#define MAXN 51
#define pii pair<int, int>

using namespace std;

int N, S, h[MAXN], e[MAXN], p[MAXN];
bool done[MAXN][1100];
pii dp[MAXN][1100];

pii calc(int cur, int time){
    if (time <= 0) return make_pair(0, 0);
    if (cur == N) return make_pair(0, 0);

    if (done[cur][time]) return dp[cur][time];

    int ans1 = 0, ans2 = 0;
    for (int i = 0; h[cur] - (i - 1) * e[cur] > 0 && i * p[cur] <= time; i++){
        int sum = 0;
        for (int j = 0; j < i; j++){
            sum += (h[cur] - j * e[cur]);
        }

        pii alt = calc(cur + 1, time - p[cur] * i);
        alt.first += sum;
        if (alt.first > ans1){
            ans1 = alt.first;
            ans2 = alt.second + i;
        } else if (ans1 == alt.first){
            ans2 = min(ans2, alt.second + i);
        }
    }

    done[cur][time] = true;
    dp[cur][time] = make_pair(ans1, ans2);
    return dp[cur][time];
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> h[i] >> e[i] >> p[i];
    cin >> S;

    memset(dp, -1, sizeof dp);
    pii ans = calc(0, S);

    printf("%d\n%d\n", ans.first, ans.second);
}

