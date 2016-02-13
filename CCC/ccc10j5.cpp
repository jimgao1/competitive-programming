#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, -1, 2, 2, 1, -1, -2, -2};
int dy[] = {-2, -2, -1, 1, 2, 2, -1, 1};

int ax, ay, bx, by;
queue<pair<int, pair<int, int> > > q;

int main(){
    scanf("%d%d%d%d", &ax, &ay, &bx, &by);

    q.push({0, {ax, ay}});
    while(!q.empty()){
        int x = q.front().second.first;
        int y = q.front().second.second;
        int st = q.front().first;
        q.pop();

        if (x <= 0 || x > 8 || y <= 0 || y > 8)
            continue;

        if (x == bx && y == by){
            cout << st << endl;
            break;
        }

        for (int i = 0; i < 8; i++){
            q.push({st + 1, {x + dx[i], y + dy[i]}});
        }
    }
}
