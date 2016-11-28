
#include <bits/stdc++.h>

#define MAXN 100010

using namespace std;

int N, tree[2][MAXN][2];

bool test(int a, int b){
    if (a < 0 && b < 0) return (a == b);
    if (a < 0 || b < 0) return false;

    if (test(tree[0][a][0], tree[1][b][0]) &&
        test(tree[0][a][1], tree[1][b][1])) return true;

    if (test(tree[0][a][1], tree[1][b][0]) &&
        test(tree[0][a][0], tree[1][b][1])) return true;

    return false;
}

int main(){
    for (int k = 0; k < 2; k++){
        cin >> N;
        for (int i = 1; i <= N; i++){
            for (int j = 0; j < 2; j++){
                cin >> tree[k][i][j];
            }
        }
    }

    if (test(1, 1)){
        cout << "Fred and Mary might have the same mobile." << endl;
    } else {
        cout << "Fred and Mary have different mobiles." << endl;
    }
}

