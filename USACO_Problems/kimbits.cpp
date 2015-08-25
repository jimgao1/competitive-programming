/*
ID: jim_yub1
LANG: C++11
TASK: kimbits
*/

#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

ull N, L, I;

ll factorial(int n) { return (n <= 1 ? 1 : n * factorial(n - 1)); }

ull nChoosek( ull n, ull k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    ull result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

string solve(string str, int used, int current, ull place){

    if (current == N) return str;

    ull pos = 0;
    for (int i = 0; i <= (L - used); i++){
        pos += nChoosek(N - current - 1, i);
        //printf("%d choose %d = ", N - current - 1, i);
        //cout << nChoosek(N - current - 1, i) << endl;
    }

    //printf("used = %d, current = %d, place = %lld\n", used, current, place);

    if (pos <= place){
        return solve(str + "1", used + 1, current + 1, place - pos);
    }

    return solve(str + "0", used, current + 1, place);
}

int main(){
    freopen("kimbits.in", "r", stdin);
    freopen("kimbits.out", "w", stdout);

    cin >> N >> L >> I;

    cout << solve("", 0, 0, I - 1) << endl;
}

