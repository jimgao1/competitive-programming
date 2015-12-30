#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

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
ll N;
int main()
{
    cin >> N;
    if (isPrime(N, 18)){
        cout << N << endl;
        return 0;
    }
    while(!isPrime(++N, 18)){}
    cout << N << endl;
}
