
#include <bits/stdc++.h>

#define MAXN 10010
#define ll long long

using namespace std;

int T, N, num[MAXN], sum[MAXN];

ll mulmod(ll a, ll b, ll mod){
    ll x = 0LL;
    ll y = a % mod;
    while(b > 0){
        if(b % 2 == 1)
            x = (x + y) % mod;
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}

ll modulo(ll base, ll exp, ll mod){
    ll x = 1LL;
    ll y = base;
    while(exp > 0){
        if(exp % 2 == 1)
            x = mulmod(x, y, mod);
        y = mulmod(y, y, mod);
        exp /= 2;
    }
    return x % mod;
}

bool isPrime(ll p, int n){
    if(p < 2)
        return false;
    if(p != 2 && p % 2 == 0)
        return false;
    ll s = p - 1;
    while(s % 2 == 0){
        s /= 2;
    }
    for(int i = 0; i < n; i++){
        ll a = rand() % (p-1) + 1;
        ll temp = s;
        ll mod = modulo(a, temp, p);
        while(temp != p-1 && mod != 1 && mod != p-1){
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if(mod != p-1 && temp % 2 == 0){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> T;
    while(T--){
        memset(num, 0, sizeof num);
        memset(sum, 0, sizeof sum);

        cin >> N;
        for (int i = 1; i <= N; i++){
            cin >> num[i];
            sum[i] = num[i] + sum[i - 1];
        }

        int mlen = 1e7, idx = -1;
        for (int i = 1; i <= N; i++){
            for (int j = i + 1; j <= min(N, i + mlen - 2); j++){
                if (isPrime(sum[j] - sum[i - 1], 10)){
                    mlen = j - i + 1;
                    idx = i;
                }
            }
        }

        if (mlen == 1e7){
            printf("This sequence is anti-primed.\n");
        } else {
            printf("Shortest primed subsequence is length %d:", mlen);
            for (int i = idx; i < idx + mlen; i++){
                printf(" %d", num[i]);
            }
            printf("\n");
        }
    }
}
