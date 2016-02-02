
#include <cstdio>
#include <queue>
#include <cstring>

#define INF 0x3f3f3f3f

using namespace std;

queue<int> q;

int N, M, widest[2001], matrix[2001][2001];
bool qcont[2001];

inline int nmax(int a, int b){ return (a > b ? a : b); }
inline int nmin(int a, int b){ return (a < b ? a : b); }

int main(){
    scanf("%d%d", &N, &M);

    memset(widest, 0x3f, sizeof widest);
    memset(matrix, 0x3f, sizeof matrix);
    memset(qcont, 0, sizeof qcont);

    for (int i = 0, a, b, l; i < M; i++){
        scanf("%d%d%d", &a, &b, &l);
        matrix[a - 1][b - 1] = nmin(matrix[a - 1][b - 1], l);
        matrix[b - 1][a - 1] = nmin(matrix[b - 1][a - 1], l);
    }

    widest[0] = 0;
    q.push(0);
    qcont[0] = true;

    while(!q.empty()){
        int current = q.front();
        qcont[current] = false;
        q.pop();

        for (int i = 0; i < N; i++){
            int alt = nmax(widest[current], matrix[current][i]);
            if (alt < widest[i]){
                widest[i] = alt;

                if (!qcont[i]){
                    qcont[i] = true;
                    q.push(i);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) ans = nmax(ans, widest[i]);

    printf("%d\n", ans);
}
