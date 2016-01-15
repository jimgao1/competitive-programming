#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

struct state{
    int r, c, st;
    state(int n1, int n2, int n3){
        r = n1, c = n2, st = n3;
    }
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int N, M, T, dist[6][6], dist2[21][21];
char grid[21][21];

vector<pair<int, int>> loc;
vector<int> order;
queue<state> q;

void calc(int id, int n, int m){
    while(!q.empty()) q.pop();
    memset(dist2, 0x3f, sizeof dist2);

    q.push(state(n, m, 0));

    while(!q.empty()){
        int cr = q.front().r, cc = q.front().c, st = q.front().st;
        q.pop();

        if (dist2[cr][cc] < st) continue;
        dist2[cr][cc] = st;

        for (int i = 0; i < 4; i++){
            int nr = cr + dx[i], nc = cc + dy[i];
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if (dist2[nr][nc] <= st + 1) continue;
            if (grid[nr][nc] == 'X') continue;

            q.push(state(nr, nc, st + 1));
        }
    }

    for (int i = 0; i < loc.size(); i++){
        dist[id][i] = dist2[loc[i].first][loc[i].second];
    }
}

int main(){
    cin >> N >> M >> T;
    for (int i = 0; i < N; i++){
        string str;
        cin >> str;
        for (int j = 0; j < M; j++){
            grid[i][j] = str[j];
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (grid[i][j] == 'G'){
                loc.push_back({i, j});
            }
        }
    }

    order.push_back(0);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (grid[i][j] == 'H'){
                loc.push_back({i, j});
                order.push_back(loc.size() - 1);
            }
        }
    }

    for (int i = 0; i < loc.size(); i++) calc(i, loc[i].first, loc[i].second);

    int ans = INF;
    do{

        int total = 0;
        for (int i = 0; i < order.size() - 1; i++){
            total += dist[order[i]][order[i + 1]];
            if (total >= INF){
                total = INF;
                break;
            }
        }

        ans = min(ans, total);
    } while(next_permutation(order.begin() + 1, order.end()));

    printf("%d\n", ans);
}
