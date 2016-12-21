[200~
#include <bits/stdc++.h>

#define MAXN 1001
#define ll long long

using namespace std;

int H, G;
ll dp[MAXN][MAXN][2];
vector<pair<int, int>> hh, gg;

int dist(pair<int, int> a, pair<int, int> b){
    return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

int main(){
    freopen("checklist.in", "r", stdin);
    freopen("checklist.out", "w", stdout);

    cin >> H >> G;
    for (int i = 0, x, y; i < H; i++){
        cin >> x >> y;
        hh.push_back({x, y});
    }
    for (int i = 0, x, y; i < G; i++){
        cin >> x >> y;
        gg.push_back({x, y});
    }

    /*
        Let dp[i][j][0] be the minimum length to be traveled when i holsteins and j guernseys are visited, and current location is at holstein
        Let dp[i][j][1] be the minimum length to be traveled when i holsteins and j guernseys are visited, and current location is at guernseys
    */

    memset(dp, 0x3f, sizeof dp);
    dp[1][0][0] = 0;
    for (int i = 0; i < H + 1; i++){
        for (int j = 0; j < G + 1; j++){
            for (int k = 0; k < 2; k++){
                if (k == 0 && i == 0) continue;
                if (k == 1 && j == 0) continue;
                pair<int, int> ploc = (k == 0 ? hh[i - 1] : gg[j - 1]);

                if (i < H){
                    dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k] + dist(ploc, hh[i]));
                }

                if (j < G){
                    dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][k] + dist(ploc, gg[j]));
                }
            }
        }
    }

    cout << dp[H][G][0] << endl;
}
[201~
