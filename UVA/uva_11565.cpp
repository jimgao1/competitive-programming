
#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    cin >> N;
    while(N--){
        int A, B, C;
        cin >> A >> B >> C;

        bool flag = false;
        for (int i = -1 * (int)sqrt(C); i <= sqrt(C); i++){
            for (int j = -1 * (int)(sqrt(C)); j <= sqrt(C); j++){
                int k = A - i - j;
                if (i == j || j == k || k == i) continue;
                if (i * j * k == B && i * i + j * j + k * k == C){
                    flag = true;
                    printf("%d %d %d\n", i, j, k);
                    break;
                }
            }
            if (flag) break;
        }

        if (!flag) printf("No solution.\n");
    }
}
