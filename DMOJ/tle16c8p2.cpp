#include <bits/stdc++.h>

using namespace std;

int T;

int main(){
    cin >> T;
    while(T--){
        unsigned int n; cin >> n;
        if (n == 0) { printf("meme\n"); continue; }

        bool flag = 0, flag2 = 0;
        for (int i = 31; i >= 0; i--){
            if (flag2) printf(" ");
            if (n & (1U << i)){
                flag = true;
                printf("dank");
                if (!flag2) flag2 = 1;
            } else if (flag){
                printf("meme");
                if (!flag2) flag2 = 1;
            }
        }
        printf("\n");
    }
}
