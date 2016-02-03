
#include <bits/stdc++.h>

using namespace std;

int diff[3][2] = {{0, 3}, {3, 0}, {1, 1}};

int T, G, ans = 0, points[5];
bool visited[5][5];

vector<pair<int, int>> matches;

void dfs(int idx){
    if (idx == matches.size()){
        int mPoints = 0, mIndex = -1;
        bool flag = false;
        for (int i = 1; i <= 4; i++){
            if (points[i] > mPoints){
                mPoints = points[i];
                mIndex = i;
                flag = false;
            } else if (points[i] == mPoints){
                flag = true;
            }
        }

        if (mIndex == T && !flag) ans++;
        return;
    }

    for (int i = 0; i < 3; i++){
        points[matches[idx].first] += diff[i][0];
        points[matches[idx].second] += diff[i][1];

        dfs(idx + 1);

        points[matches[idx].first] -= diff[i][0];
        points[matches[idx].second] -= diff[i][1];
    }
}

int main(){
    scanf("%d%d", &T, &G);
    for (int i = 0, a, b, pa, pb; i < G; i++){
        scanf("%d%d%d%d", &a, &b, &pa, &pb);

        visited[a][b] = true;
        visited[b][a] = true;

        if (pa == pb){
            points[a] += 1;
            points[b] += 1;
        } else if (pa > pb){
            points[a] += 3;
        } else {
            points[b] += 3;
        }
    }

    for (int i = 1; i < 5; i++){
        for (int j = i + 1; j < 5; j++){
            if (!visited[i][j]){
                matches.push_back({i, j});
            }
        }
    }

    dfs(0);

    printf("%d\n", ans);
}
