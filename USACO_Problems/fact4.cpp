/*
USER: jim.yub1
LANG: C++
TASK: fact4
*/

#include <bits/stdc++.h>

using namespace std;

int N;
long long D = 1;

int main(){
    freopen("fact4.in", "r", stdin);
    freopen("fact4.out", "w", stdout);

    scanf("%d", &N);

    for (int i = 2; i <= N; i++){
        D = D * i % 1000000;
        while(D % 10 == 0) D /= 10;
    }

    printf("%d\n", D % 10);

    return 0;
}
