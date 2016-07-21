
#include <bits/stdc++.h>

using namespace std;

int main(){
    long long N, K;
    cin >> N >> K;

    if (N % K == 0){
        printf("0\n");
    } else {
        if (N < K)
            cout << K - N << endl;
        else
            cout << min(N % K, K - (N % K));
    }

}
