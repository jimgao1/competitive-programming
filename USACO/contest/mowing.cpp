
#include <bits/stdc++.h>

#define MAXN 2001

using namespace std;

int N, last[MAXN][MAXN], maxspan[MAXN][MAXN];

int main(){
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);

    cin >> N;
    int cr = 1000, cc = 1000, t = 0;
    for (int i = 0; i < N; i++){
        string dir;
        int cnt, dr, dc;
        cin >> dir >> cnt;

        if (dir == "N")
            dr = -1, dc = 0;
        else if (dir == "S")
            dr = 1, dc = 0;
        else if (dir == "W")
            dr = 0, dc = -1;
        else if (dir == "E")
            dr = 0, dc = 1;

        for (int i = 0; i < cnt; i++){
            cr += dr, cc += dc;
            t++;
            if (last[cr][cc] != 0)
                maxspan[cr][cc] = max(maxspan[cr][cc], t - last[cr][cc]);
            last[cr][cc] = t;
        }
    }

    int ans = 0x3f3f3f3f;
    for (int i = 0; i < MAXN; i++){
        for (int j = 0; j < MAXN; j++){
            if (maxspan[i][j] != 0)
                ans = min(ans, maxspan[i][j]);
        }
    }

    if (ans == 0x3f3f3f3f)
        cout << -1 << endl;
    else
        cout << ans << endl;
}
