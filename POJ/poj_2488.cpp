
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <cstring>

using namespace std;

int dy[] = {-2, -2, -1, -1,  1, 1,  2, 2};
int dx[] = {-1,  1, -2,  2, -2, 2, -1, 1};

bool visited[26][26];
int gridX, gridY;
vector<pair<int, int> > history;

bool dfs(int x, int y){
    if (visited[x][y]) return false;
    visited[x][y] = true;
    if (history.size() == gridX * gridY) return true;

    for (int i = 0; i < 8; i++){
        int newX = x + dx[i], newY = y + dy[i];

        if (newX < 0 || newX >= gridX || newY < 0 || newY >= gridY)
            continue;
        if (visited[newX][newY]) continue;

        history.push_back({ newX, newY} );
        if (dfs(newX, newY))
            return true;
        history.pop_back();
    }

    visited[x][y] = false;
    return false;
}

int main(){
    int caseCount;
    cin >> caseCount;

    for (int i = 0; i < caseCount; i++){
        cout << "Scenario #" << (i + 1) << ":\n";

        cin >> gridX >> gridY;
        /*
        bool impossible = true;

        for (int i = 0; i < gridX; i++){
            for (int j = 0; j < gridY; j++){
                history.push_back({i, j});
                if (dfs(i, j)){
                    for (int k = 0; k < history.size(); k++)
                        cout << (char)(history[k].second + 'A') << (history[k].first + 1);
                    cout << endl;
                    impossible = false;
                    goto hell;
                }
                history.clear();
                memset(visited, false, sizeof visited);
            }
        }

        hell:
        if (impossible)
            cout << "impossible" << endl;
        cout << endl;
        */

        memset(visited, false, sizeof visited);
        history.clear();
        history.push_back({0, 0});
        if (dfs(0, 0)){
            for (int i = 0; i < history.size(); i++)
                cout << (char)(history[i].second + 'A') << (history[i].first + 1);
            cout << endl;
        } else {
            cout << "impossible" << endl;
        }

        cout << endl;
    }
}
