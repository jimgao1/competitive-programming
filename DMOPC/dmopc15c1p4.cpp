
#include <bits/stdc++.h>

#define MAXN 148736

using namespace std;

int N, X, cnt = 0;
bool prime[MAXN];

void sieve(){
    memset(prime, 1, sizeof prime);
    prime[0] = false, prime[1] = false;

    for (int i = 2; i < MAXN; i++){
        if (!prime[i]) continue;
        for (int j = i * 2; j < MAXN; j += i){
            prime[j] = false;
        }
    }
}

int main(){
    sieve();

    cin >> N >> X;
    for (int i = 2; i <= N; i++){
        if (!prime[i]) continue;
        cnt += ((N - i) / X + 1) * 2;
        if ((N - i) % X == 0) cnt--;
    }

    cout << cnt << endl;
}
