#include <bits/stdc++.h>

using namespace std;

int N, ans = 0;
bool ext[100001];
vector<int> balls;

int main(){
    freopen("snowman.txt", "r", stdin);

    scanf("%d", &N);
    for (int i = 0, x; i < N; i++){
        scanf("%d", &x);
        balls.push_back(x);
        ext[x] = true;
    }

    sort(balls.begin(), balls.end());

    for (int i = 0; i < N; i++){
        for (int j = i + 1; j < N; j++){
            if (balls[i] == balls[j]) continue;
            int n = balls[j] + (balls[j] - balls[i]);
            if (n <= 100000 && ext[n]){
                ans = max(ans, balls[i] + balls[j] + n);
            }
        }
    }

    printf("%d\n", ans);
}
