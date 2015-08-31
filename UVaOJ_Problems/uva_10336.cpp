
#include <bits/stdc++.h>

using namespace std;

int T, sizeX, sizeY, cnt[26];
char m[31][31];
bool visited[31][31];

vector<pair<int, char>> n;

bool flood_fill(int x, int y, char c){
    if (x < 0 || x >= sizeX || y < 0 || y >= sizeY) return false;
    if (visited[x][y]) return false;
    if (m[x][y] != c) return false;

    visited[x][y] = true;

    flood_fill(x - 1, y, c);
    flood_fill(x + 1, y, c);
    flood_fill(x, y - 1, c);
    flood_fill(x, y + 1, c);

    return true;
}

bool comp(pair<int, char> a, pair<int, char> b){
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

int main(){
    cin >> T;
    for (int t = 1; t <= T; t++){
        memset(visited, 0, sizeof visited);
        memset(m, 0, sizeof m);
        memset(cnt, 0, sizeof cnt);
        n.clear();

        cin >> sizeY >> sizeX;

        for (int i = 0; i < sizeY; i++)
            for (int j = 0; j < sizeX; j++)
                cin >> m[j][i];

        for (int i = 0; i < sizeX; i++){
            for (int j = 0; j < sizeY; j++){
                if (!visited[i][j]){
                    if (flood_fill(i, j, m[i][j]))
                        cnt[m[i][j] - 'a'] ++;
                }
            }
        }

        for (int i = 'a'; i <= 'z'; i++){
            if (cnt[i - 'a'] > 0) n.push_back({cnt[i - 'a'], i});
        }

        sort(n.begin(), n.end(), comp);

        printf("World #%d\n", t);
        for (int i = 0; i < n.size(); i++){
            printf("%c: %d\n", n[i].second, n[i].first);
        }
    }
}
