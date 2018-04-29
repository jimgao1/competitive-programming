

#include <bits/stdc++.h>

#define MAXN 1000006
#define ll long long

using namespace std;

ll K, M;
ll maxFactor = 1, maxCnt = 0;

bool notPrime[MAXN + 10];
vector<ll> primes;
unordered_map<ll, ll> factorCount;

void sieve() {
    for (ll i = 2; i <= MAXN; i++) {
        if (notPrime[i]) continue;
        primes.push_back(i);
        for (ll j = i + i; j <= MAXN; j += i)
            notPrime[j] = true;
    }
}

void init() {
    maxFactor = 0, maxCnt = 0;
    factorCount.clear();
}

ll fuckPow(ll base, ll exp) {
    ll ans = 1LL;
    while (exp--) ans *= base;
    return ans;
}

void maxPrimeFactor(int val) {
    ll maxValue = 0;

    for (int p : primes) {
        if (p > val) break;
        if (val % p == 0) {
            ll cnt = 0, tmp = val;
            while (tmp % p == 0) cnt++, tmp /= p;
            ll fuck = fuckPow(p, cnt);
//            printf("p = %lld, cnt = %lld, fuck = %lld\n", p, cnt, fuck);
            if (fuck > maxValue) maxFactor = p, maxCnt = cnt, maxValue = fuck;
        }
    }
}

void solve() {
    cin >> K >> M;
//    printf("K = %lld, M = %lld\n", K, M);

    maxPrimeFactor(K);
//    printf("maxFactor = %lld, maxCnt = %lld\n", maxFactor, maxCnt);

    ll finalAns = 0;

    for (ll curFactor : primes) {
        if (curFactor > K) break;
        if (K % curFactor != 0) continue;

        ll curCnt = 0;
        ll tmp = K;
        while (tmp % curFactor == 0) curCnt++, tmp /= curFactor;

//        printf("curFactor = %lld, curCnt = %lld\n", curFactor, curCnt);

        for (ll n = curFactor, count = 0;; n += curFactor) {
            ll num = n;
            while (num % curFactor == 0) {
                num /= curFactor;
                count++;
            }

//        printf("n = %d, count = %d\n", n, count);
            if (count >= M * curCnt) {
                finalAns = max(finalAns, n);
                break;
            }
        }
    }

    cout << finalAns << endl;
}

int main() {
    freopen("/home/jim/ecoo/DATA32.txt", "r", stdin);

    sieve();

    int T = 10;
    while (T--) {
        init();
        solve();
    }
}
