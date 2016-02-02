
#include <bits/stdc++.h>

using namespace std;

int N, Q, sum[500001];

int main(){
    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; i++) scanf("%d", &sum[i]);
    for (int i = 2; i <= N; i++) sum[i] += sum[i - 1];

    for (int i = 0, a, b; i < Q; i++){
        scanf("%d%d", &a, &b);
        printf("%d\n", sum[N] - (sum[b] - sum[a - 1]));
    }
}
