
/*
    SPOJ Problem HAYBALE - Difference Array Approach
*/

#include <bits/stdc++.h>

using namespace std;

int N, K;
short h[10000001];

vector<int> num;

int main(){
    scanf("%d %d", &N, &K);
    memset(h, 0, sizeof(short) * 10000001);

    h[0] = 0;
    for (int i = 0, x, y; i < K; i++){
        scanf("%d %d", &x, &y);
        h[x] += 1;
        h[y] -= 1;
    }

    num.push_back(h[0]);
    for (int i = 1; i < N; i++){
        num.push_back(h[i] + h[i - 1]);
        h[i] = h[i] + h[i - 1];
    }

    sort(num.begin(), num.end());

    printf("%d\n", num[num.size() / 2 + 1]);

    return 0;
}
