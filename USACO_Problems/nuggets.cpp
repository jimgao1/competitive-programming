/*
ID: jim_yub1
LANG: C++11
TASK: nuggets
*/

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, num[11], rmax = 0;
bool dp[10000000];

queue<int> m;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b){
    int temp = gcd(a, b);
    return temp ? (a / temp * b) : 0;
}

int main(){
    freopen("nuggets.in", "r", stdin);
    freopen("nuggets.out", "w", stdout);

    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &num[i]);
    sort(num, num + N);

    bool flag = true;
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            if (gcd(num[i], num[j]) == 1)
                flag = false;

    if (flag){
        printf("0\n");
        return 0;
    }

    for (int i = 0; i < N; i++){
        m.push(num[i]);
        dp[num[i]] = true;
    }

    dp[0] = true;
    for (int i = 0; i <= 100000; i++){
        if (!dp[i]){
            rmax = i;
        } else {
            for (int j = 0; j < N; j++)
                if (i + num[j] <= 100000)
                    dp[i + num[j]] = true;
        }
    }

    printf("%d\n", rmax);
}
