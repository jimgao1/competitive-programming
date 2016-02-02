
#include <bits/stdc++.h>

/*
        Are you sure this is an IOI problem?
*/

using namespace std;

int N, K, cur = 0, msum = 0;
int num[1000001];

int nmax(int a, int b){
    return (a > b ? a : b);
}

int main(){
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) scanf("%d", &num[i]);

    for (int i = 0; i < N; i++){
        if (i >= K){
            cur -= num[i - K];
        }

        cur += num[i];
        msum = nmax(msum, cur);
    }

    printf("%d\n", msum);
    
    return 0;
}
