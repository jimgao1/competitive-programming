
#include <bits/stdc++.h>

#define MAXN 101

using namespace std;

int N;
bool explode[MAXN];
vector<int> loc;

int test(int cl){
    queue<pair<int, int>> q;
    memset(explode, 0, sizeof explode);
    int cnt = 0;
    q.push({cl, 1});

    explode[cl] = true;
    while(!q.empty()){
        int cur = q.front().first, r = q.front().second;
        q.pop();

        for (int i = cur - 1; i >= 0; i--){
            if (loc[cur] - loc[i] > r) break;
            if (explode[i]) continue;
            explode[i] = true;
            q.push({i, r + 1});
        }

        for (int i = cur + 1; i < N; i++){
            if (loc[i] - loc[cur] > r) break;
            if (explode[i]) continue;
            explode[i] = true;
            q.push({i, r + 1});
        }
    }

    for (int i = 0; i < N; i++)
        if (explode[i]) cnt++;

    return cnt;
}

int main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    cin >> N;
    for (int i = 0, x; i < N; i++){
        cin >> x;
        loc.push_back(x);
    }

    sort(loc.begin(), loc.end());

    int ans = 0;
    for (int i = 0; i < N; i++){
        ans = max(ans, test(i));
    }

    cout << ans << endl;
}

