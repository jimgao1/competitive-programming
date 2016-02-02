
#include <bits/stdc++.h>

#define MAXN 1000001

using namespace std;

int R, C, cnt = 0;
int dset[MAXN];
bool v[MAXN];
char grid[1001][1001];

void build(){
    for (int i = 0; i < MAXN; i++)
        dset[i] = i;
}

int ufind(int n){
    while(n != dset[n])
        n = dset[n];
    return n;
}

void umerge(int a, int b){
    int ra = ufind(a), rb = ufind(b);
    if (ra == rb) return;
    dset[ra] = rb;
}

int id(int r, int c){
    return r * C + c;
}

int main(){
    build();

    cin >> R >> C;
    for (int i = 0; i < R; i++){
        string line;
        cin >> line;
        for (int j = 0; j < C; j++){
            grid[i][j] = line[j];
        }
    }

    for (int r = 0; r < R; r++){
        for (int c = 0; c < C; c++){
            int nr, nc;

            if (grid[r][c] == 'N'){
                nr = r - 1, nc = c;
            } else if (grid[r][c] == 'S'){
                nr = r + 1, nc = c;
            } else if (grid[r][c] == 'W'){
                nr = r, nc = c - 1;
            } else if (grid[r][c] == 'E'){
                nr = r, nc = c + 1;
            }

            umerge(id(nr, nc), id(r, c));
        }
    }

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (!v[ufind(id(i, j))])
                cnt++, v[ufind(id(i, j))] = true;

    cout << cnt << endl;
}
