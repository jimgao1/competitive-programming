
#include <bits/stdc++.h>

using namespace std;

int T, N, i, a, b, c;

int main(){
    cin >> T;
    while(T--){
        cin >> N;
        a = N, b = 0, c = 0;

        for (i = 0; a + b > 1; i++){
            printf("Round %d: %d undefeated, %d one-loss, %d eliminated\n", i, a, b, c);

            if (a == 1 && b == 1){
                a = 0, b = 2;
                continue;
            }
            c += b / 2;
            b -= (b / 2);
            b += (a / 2);
            a -= (a / 2);
        }

        printf("Round %d: %d undefeated, %d one-loss, %d eliminated\n", i, a, b, c);
        printf("There are %d rounds.\n", i);
    }
}
