#include <bits/stdc++.h>

#define MAXN 1001

using namespace std;

struct hall{
    int x1, y1, x2, y2;
    hall(int a, int b, int c, int d){
        x1 = a, y1 = b, x2 = c, y2 = d;
    }
};

int H, N, M, pre[MAXN];
bool visited[MAXN], matrix[MAXN][MAXN];
vector<hall> x, y;

bool hungary(int cur){
    for (int i = 0; i < y.size(); i++){
        if (matrix[cur][i] && !visited[i]){
            visited[i] = true;
            if (pre[i] == -1 || hungary(pre[i])){
                pre[i] = cur;
                return true;
            }
        }
    }
    return false;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("camera.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> H;
    for (int i = 0; i < H; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);

        if (y1 == y2)
            x.push_back(hall(x1, y1, x2, y2));
        else
            y.push_back(hall(x1, y1, x2, y2));
    }

    for (int i = 0; i < x.size(); i++){
        for (int j = 0; j < y.size(); j++){
            hall a = x[i], b = y[j];
            if (b.y1 <= a.y1 && a.y1 <= b.y2 &&
                a.x1 <= b.x1 && b.x1 <= a.x2) {

                matrix[i][j] = true;
                //printf("%d -> %d\n", i, j);
            }
        }
    }

    //printf("N = %d\n", N);

    int K = 0;
    for (int i = 0; i < y.size(); i++)
        pre[i] = -1;

    for (int i = 0; i < x.size(); i++){
        memset(visited, 0, sizeof visited);
        if (hungary(i)) K++;
    }

    //printf("K = %d\n", K);

    K += (H - K * 2);

    cout << K << endl;
}
