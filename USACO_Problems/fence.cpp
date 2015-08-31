/*
ID: jim_yub1
LANG: C++11
TASK: fence
*/

#include <bits/stdc++.h>

using namespace std;

int F, oddCnt = 0, oddNode, evenNode, deg[501];
int matrix[501][501];
vector<int> circuit;

void find_circuit(int node){
    for (int i = 0; i < 500; i++){
        if (matrix[node][i] > 0){
            matrix[node][i] -= 1;
            matrix[i][node] -= 1;

            find_circuit(i);
        }
    }

    circuit.push_back(node);
}

int main(){
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);

    memset(matrix, 0, sizeof matrix);

    scanf("%d", &F);

    for (int i = 0, x, y; i < F; i++){
        scanf("%d%d", &x, &y);
        matrix[x - 1][y - 1] += 1;
        matrix[y - 1][x - 1] += 1;

        deg[x - 1] ++, deg[y - 1] ++;
    }

    for (int i = 0; i < 500; i++){
        if (deg[i] % 2 == 1) oddCnt ++;
    }

    if (oddCnt == 2){
        for (int i = 0; i < 500; i++){
            if (deg[i] % 2 == 1){
                find_circuit(i);
                break;
            }
        }
    } else {
        for (int i = 0; i < 500; i++){
            if (deg[i] % 2 == 0){
                find_circuit(i);
                break;
            }
        }
    }

    reverse(circuit.begin(), circuit.end());
    for (int x : circuit) printf("%d\n", x + 1);
}
