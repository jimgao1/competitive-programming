
#include <bits/stdc++.h>

#define ll long long
#define MAXN 10000001

using namespace std;

int N;
bool prime[MAXN];

int main(){
    for (int i = 2; i < MAXN; i++){
        if (prime[i]) continue;
        for (int j = i * 2; j < MAXN; j += i){
            prime[j] = true;
        }
    }

    scanf("%d", &N);
    for (int i = 0, x; i < N; i++){
        scanf("%d", &x);
        while(x > 1){
            if (!prime[x]){
                printf("%d\n", x);
                break;
            }
            for (int j = 2; j * j <= x; j++){
                if (x % j == 0 && !prime[j]){
                    printf("%d ", j);
                    x = x / j;
                    break;
                }
            }
        }
    }
}
