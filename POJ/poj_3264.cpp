
#include <cstdio>
#include <cmath>
#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;

int N, Q, num[50001];
int maxnum[50001][20], minnum[50001][20];

void init(){
    for (int i = 1; i <= N; i++)
        minnum[i][0] = num[i], maxnum[i][0] = num[i];

    for (int i = 1; (1 << i) <= N; i++){
        for (int j = 1; j + (1 << i) - 1 <= N; j++){
            maxnum[j][i] = max(maxnum[j][i - 1], maxnum[j + (1 << (i - 1))][i - 1]);
            minnum[j][i] = min(minnum[j][i - 1], minnum[j + (1 << (i - 1))][i - 1]);
        }
    }
}

int queryMax(int a, int b){
    int k = (int)(log(double(b - a + 1))/log((double)2));
    return max(maxnum[a][k], maxnum[b - (1 << k) + 1][k]);
}

int queryMin(int a, int b){
    int k = (int)(log(double(b - a + 1))/log((double)2));
    return min(minnum[a][k], minnum[b - (1 << k) + 1][k]);
}

int main(){
    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; i++) scanf("%d", &num[i]);

    init();

    for (int i = 0, a, b; i < Q; i++){
        scanf("%d%d", &a, &b);

        int na = queryMax(a, b);
        int nb = queryMin(a, b);

        printf("%d\n", na - nb);
    }
}
