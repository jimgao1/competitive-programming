
#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

int X, Y, M, ans = 0;
bool visited[MAXN];
queue<int> q;

int main(){
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    cin >> X >> Y >> M;
    q.push(0);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if (cur > M) continue;
        ans = max(ans, cur);

        if (visited[cur]) continue;
        visited[cur] = true;

        if (cur + X <= M && !visited[cur + X])
            q.push(cur + X);

        if (cur + Y <= M && !visited[cur + Y])
            q.push(cur + Y);
    }

    cout << ans << endl;
}

