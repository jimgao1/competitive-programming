//I love smoking magic mushrooms xD

#include <bits/stdc++.h>

#define MAXN 110000

using namespace std;

int N, K, vert[MAXN], hor[MAXN], diag1[MAXN * 2], diag2[MAXN * 2];

int main(){
    cin >> N >> K;
    for (int i = 0, x, y; i < N; i++){
        cin >> x >> y;
        x--, y--;

        //Horizontal
        hor[x] ++;
        if (hor[x] >= K){
            cout << i + 1 << endl;
            return 0;
        }

        //Vertical
        vert[y] ++;
        if (vert[y] >= K){
            cout << i + 1 << endl;
            return 0;
        }

        //Diagonal 1
        diag1[x + y - 1] ++;
        if (diag1[x + y - 1] >= K){
            cout << i + 1 << endl;
            return 0;
        }

        //Diagonal 2
        diag2[x - y + MAXN] ++;
        if (diag2[x - y + MAXN] >= K){
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}
