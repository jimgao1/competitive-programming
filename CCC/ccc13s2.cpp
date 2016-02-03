
#include <bits/stdc++.h>

using namespace std;

int W, N, cur = 0, ans = 0;
vector<int> v;

int main(){
    scanf("%d%d", &W, &N);
    for (int i = 0, x; i < N; i++){
        scanf("%d", &x);
        v.push_back(x);
    }

    for (int i = 0; i < v.size(); i++){
        int sum = 0;
        for (int j = i; j >= i - 3 && j >= 0; j--){
            sum += v[j];
        }

        if (sum <= W)
            ans++;
        else
            break;
    }

    printf("%d\n", ans);
}
