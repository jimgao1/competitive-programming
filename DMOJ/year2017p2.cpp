#include <bits/stdc++.h>

using namespace std;

struct state{
    int x, y, st;
    state(int a, int b, int c){
        x = a, y = b, st = c;
    }
};

int M, N, X, Y, R, E;
vector<pair<int, int>> px, py, rocks, exits;
queue<state> q;
set<pair<int, int>> visited;

int main(){
    cin >> M >> N >> X >> Y >> R;
    for (int i = 0, x, y; i < R; i++){
        cin >> x >> y;
        rocks.push_back({x, y});
        px.push_back({x, y}); py.push_back({y, x});
    }
    cin >> E;
    for (int i = 0, x, y; i < E; i++){
        cin >> x >> y;
        exits.push_back({x, y});
        px.push_back({x, y}); py.push_back({y, x});
    }
    sort(rocks.begin(), rocks.end());
    sort(exits.begin(), exits.end());
    sort(px.begin(), px.end()); sort(py.begin(), py.end());
/*
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++){
            if (i == Y && j == X){
                printf("i");
            } else if (binary_search(rocks.begin(), rocks.end(), make_pair(j, i))){
                printf("X");
            } else if (binary_search(exits.begin(), exits.end(), make_pair(j, i))){
                printf("E");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
*/

    q.push(state(X, Y, 0));
    while(!q.empty()){
        state cur = q.front(); q.pop();
        //printf("X = %d, Y = %d, Steps = %d\n", cur.x, cur.y, cur.st);

        if (visited.find(make_pair(cur.x, cur.y)) != visited.end()) continue;
        visited.insert(make_pair(cur.x, cur.y));

        if (binary_search(exits.begin(), exits.end(), make_pair(cur.x, cur.y))){
            printf("%d\n", cur.st - 1);
            return 0;
        }

        int idx1 = upper_bound(px.begin(), px.end(), make_pair(cur.x, cur.y)) - px.begin();
        //printf("idx1 = %d\n", idx1);
        if (idx1 < px.size()){
            pair<int, int> down = px[idx1];

            if (down.first == cur.x){
                q.push(state(down.first, down.second, cur.st + 1));
                //printf("down: (%d, %d)\n", down.first, down.second);
            }
        }

        idx1--;
        if (cur.x != X || cur.y != Y) idx1--;
        if (idx1 >= 0){
            pair<int, int> up = px[idx1];
            if (up.first == cur.x){
                q.push(state(up.first, up.second, cur.st + 1));
                //printf("up: (%d, %d)\n", up.first, up.second);
            }
        }

        int idx2 = upper_bound(py.begin(), py.end(), make_pair(cur.y, cur.x)) - py.begin();
        //printf("idx2 = %d\n", idx2);
        if (idx2 < py.size()){
            pair<int, int> right = py[idx2];
            if (right.first == cur.y){
                q.push(state(right.second, right.first, cur.st + 1));
                //printf("right: (%d, %d)\n", right.second, right.first);
            }
        }

        idx2--;
        if (cur.x != X || cur.y != Y) idx2--;
        if (idx2 >= 0){
            pair<int, int> left = py[idx2];

            if (left.first == cur.y){
                q.push(state(left.second, left.first, cur.st + 1));
                //printf("left: (%d, %d)\n", left.second, left.first);
            }
        }
    }

    printf("-1\n");
}
