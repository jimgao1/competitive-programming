#include <bits/stdc++.h>

#define MAXN 11

using namespace std;

int R, C, K;
char grid[MAXN][MAXN];

int main(){
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    cin >> R >> C >> K;
    for (int i = 0; i < R; i++){
        string line;
        cin >> line;
        for (int j = 0; j < C; j++){
            grid[i][j] = line[j];
        }
    }
    for (int i = 0; i < R * K; i++){
        for (int j = 0; j < C * K; j++){
            cout << (grid[i / K][j / K]);
        }
        cout << endl;
    }
}

