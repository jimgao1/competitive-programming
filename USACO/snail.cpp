/*
ID: jim_yub1
LANG: C++11
TASK: snail
*/

#include <bits/stdc++.h>

#define MAXN 121

using namespace std;

int dr[] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};

int N, B, dist[MAXN][MAXN];
bool board[MAXN][MAXN], visited[MAXN][MAXN];

int dfs(int r, int c) {
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        int cr = r, cc = c;
        bool flag = false;

        while (cr >= 0 && cr < N && cc >= 0 && cc < N && !board[cr][cc] && !visited[cr][cc]) {
            cr += dr[i], cc += dc[i];
            flag |= visited[cr][cc];
        }
        cr -= dr[i], cc -= dc[i];

        if (cr == r && cc == c) continue;

        int cnt = 0;
        for (int cur_r = r, cur_c = c; cur_r != cr || cur_c != cc; cur_r += dr[i], cur_c += dc[i]) visited[cur_r][cur_c] = true, cnt++;

        if (flag)
            ans = max(ans, cnt);
        else
            ans = max(ans, dfs(cr, cc) + cnt);
        for (int cur_r = r, cur_c = c; cur_r != cr || cur_c != cc; cur_r += dr[i], cur_c += dc[i]) visited[cur_r][cur_c] = false;
    }

    return ans;
}

int main() {
    freopen("snail.in", "r", stdin);
    freopen("snail.out", "w", stdout);

    cin >> N >> B;
    memset(dist, 0, sizeof dist);

    for (int i = 0; i < B; i++) {
        string str;
        cin >> str;
        int id = 0;
        if (str.size() == 2){
            id = str[1] - '0';
        } else if (str.size() == 3){
            id = 10 * (str[1] - '0') + (str[2] - '0');
        } else if (str.size() == 4){
            id = 100 * (str[1] - '0') + 10 * (str[2] - '0') + (str[3] - '0');
        }
        id--;

        board[id][str[0] - 'A'] = true;
    }

    cout << dfs(0, 0) + 1 << endl;
}
