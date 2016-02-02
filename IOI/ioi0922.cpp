
#include <bits/stdc++.h>

using namespace std;

struct point{
    int r, c, st;
    point(int _, int __, int ___){
        r = _, c = __, st = ___;
    }
};

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

int N, S, hr, hc, tr, tc, dist[801][801];
char grid[801][801];
bool visited[801][801];

queue<point> bfs;

bool tbfs(int wait){
    while(!bfs.empty()) bfs.pop();
    memset(visited, 0, sizeof visited);

    bfs.push(point(hr, hc, wait * S));
    while(!bfs.empty()){
        int cr = bfs.front().r, cc = bfs.front().c, cst = bfs.front().st;
        bfs.pop();

        //printf("cr = %d, cc = %d, cst = %d\n", cr, cc, cst);

        if (cr < 0 || cr >= N || cc < 0 || cc >= N) continue;
        if (grid[cr][cc] == 'D') return true;

        if (dist[cr][cc] * S <= cst) {
            continue;
        }
        if (grid[cr][cc] == 'T') {
            continue;
        }

        if (visited[cr][cc]) continue;
        visited[cr][cc] = true;

        for (int i = 0; i < 4; i++)
            bfs.push(point(cr + dx[i], cc + dy[i], cst + 1));
    }

    return false;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++){
        string line;
        cin >> line;
        for (int j = 0; j < N; j++){
            grid[i][j] = line[j];

            if (grid[i][j] == 'H'){
                bfs.push(point(i, j, 0));
            } else if (grid[i][j] == 'M'){
                hr = i, hc = j;
            }
        }
    }

    memset(dist, 0x3f, sizeof dist);
    while(!bfs.empty()){
        int cr = bfs.front().r, cc = bfs.front().c, cst = bfs.front().st;
        bfs.pop();

        if (grid[cr][cc] == 'T' || grid[cr][cc] == 'D') continue;

        if (visited[cr][cc]) continue;
        visited[cr][cc] = true;
        dist[cr][cc] = cst;

        for (int i = 0; i < 4; i++){
            int dr = cr + dx[i], dc = cc + dy[i];
            if (dr < 0 || dr >= N || dc < 0 || dc >= N) continue;
            bfs.push(point(dr, dc, cst + 1));
        }
    }

    int low = 0, high = N * N, ans = tbfs(0) - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if (tbfs(mid)){
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%d\n", ans);

}
