#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

struct point{
    int x, y, z;

    bool operator<(const point& rhs) const
    {
        return x < rhs.x;
    }
};

int X, Y, Z, maze[151][151][151], dist[151][151][151];
point init;

vector<point> dir;

priority_queue<pair<int, point>, vector<pair<int, point>>, greater<pair<int, point>>> q;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    dir.push_back({0, 0, 1});
    dir.push_back({0, 0, -1});
    dir.push_back({0, 1, 0});
    dir.push_back({0, -1, 0});
    dir.push_back({1, 0, 0});
    dir.push_back({-1, 0, 0});

    cin >> X >> Y >> Z;
    for (int i = 0; i < X; i++){
        for (int j = 0; j < Y; j++){
            string line;
            cin >> line;
            for (int k = 0; k < Z; k++){
                if (line[k] == 'J'){
                    init.x = i, init.y = j, init.z = k;
                } else {
                    maze[i][j][k] = line[k] - '0';
                }
            }
        }
    }

    memset(dist, 0x3f, sizeof dist);
    q.push({0, init});
    dist[init.x][init.y][init.z] = 0;

    while(!q.empty()){
        point cur = q.top().second;
        int st = q.top().first;
        q.pop();

        if (cur.x == 0 || cur.x == X - 1 ||
            cur.y == 0 || cur.y == Y - 1 ||
            cur.z == 0 || cur.z == Z - 1){

            cout << st << "\n";
            break;
        }

        for (point d : dir){
            int nx = cur.x + d.x, ny = cur.y + d.y , nz = cur.z + d.z;


            if (dist[nx][ny][nz] > dist[cur.x][cur.y][cur.z] + maze[nx][ny][nz]){
                dist[nx][ny][nz] = dist[cur.x][cur.y][cur.z] + maze[nx][ny][nz];

                q.push({dist[nx][ny][nz], {nx, ny, nz}});
            }
        }
    }
}
