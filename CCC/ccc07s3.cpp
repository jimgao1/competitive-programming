
#include <bits/stdc++.h>

using namespace std;

int N, f[10001], dist[10001];

int main(){
    scanf("%d", &N);
    for (int i = 0, x, y; i < N; i++){
        scanf("%d%d", &x, &y);
        f[x] = y;
    }

    while(true){
        bool flag = true;

        int a, b;
        scanf("%d%d", &a, &b);

        if (a == 0 && b == 0) break;
        memset(dist, 0, sizeof dist);

        int cur = f[a];
        dist[f[a]] = 1;
        while(true){
            if (cur == a) break;

            if (dist[f[cur]] > 0){
                flag = false;
                break;
            }
            dist[f[cur]] = dist[cur] + 1;

            cur = f[cur];
        }

        if (dist[b] == 0) flag = false;

        if (flag){
            printf("Yes %d\n", dist[b] - 1);
        } else {
            printf("No\n");
        }
    }
}
