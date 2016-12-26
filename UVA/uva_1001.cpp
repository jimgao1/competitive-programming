[200~
#include <bits/stdc++.h>

#define MAXN 201

using namespace std;

struct hole{
    int x, y, z, r;
    hole(int a, int b, int c, int d){
        x = a, y = b, z = c, r = d;
    }
};

int N;
double matrix[MAXN][MAXN];
vector<hole> h;

double dist(hole a, hole b){
    return max(sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2)) - a.r - b.r, 0.0);
}

int main(){
    int cc = 1;
    while(true) {
        h.clear();
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++)
                matrix[i][j] = 1e9;

        cin >> N;
        if (N == -1) break;
        for (int i = 0, a, b, c, d; i < N; i++) {
            cin >> a >> b >> c >> d;
            h.push_back(hole(a, b, c, d));
        }
        int a, b, c;
        cin >> a >> b >> c;
        h.insert(h.begin(), hole(a, b, c, 0));
        cin >> a >> b >> c;
        h.push_back(hole(a, b, c, 0));


        for (int i = 0; i < h.size(); i++) {
            for (int j = 0; j < h.size(); j++) {
                matrix[i][j] = dist(h[i], h[j]);
            }
        }

        for (int k = 0; k < h.size(); k++)
            for (int i = 0; i < h.size(); i++)
                for (int j = 0; j < h.size(); j++)
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);

        printf("Cheese %d: Travel time = %.0f sec\n", cc++, matrix[0][h.size() - 1] * 10);
    }
}[201~
