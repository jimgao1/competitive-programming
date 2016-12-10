//Minimum Representation

#include <bits/stdc++.h>

#define MAXN 11
#define ll long long

using namespace std;

int N, G;
bool grid[MAXN][MAXN];
map<string, int> fuckshit;

int main(){
    cin >> N >> G;
    for (int i = 0; i < G; i++){
        memset(grid, 0, sizeof grid);
        for (int j = 0; j < N; j++){
            string line;
            cin >> line;
            for (int k = 0; k < N; k++) {
                if (line[k] == 'R') {
                    grid[j][k] = true;
                }
            }
        }

        while(true) {
            bool flag = false;
            for (int j = 0; j < N - 1; j++) {
                for (int k = 0; k < N - 1; k++) {
                    if (grid[j][k]) {
                        grid[j][k] = !grid[j][k];
                        grid[j + 1][k] = !grid[j + 1][k];
                        grid[j][k + 1] = !grid[j][k + 1];
                        grid[j + 1][k + 1] = !grid[j + 1][k + 1];

                        flag = true;
                    }
                }
            }

            if (!flag) break;
        }

        stringstream ss;
        for (int j = 0; j < N; j++) {
            ss << (grid[j][N - 1] ? "1" : "0");
        }
        for (int j = 0; j < N; j++){
            ss << (grid[N - 1][j] ? "1" : "0");
        }

        fuckshit[ss.str()] ++;
    }

    ll fuckfuckshit = 0;
    for (const pair<string, int> &shit : fuckshit){
        fuckfuckshit += shit.second * (shit.second - 1) / 2;
    }

    cout << fuckfuckshit << endl;
}
