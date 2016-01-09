
#include <bits/stdc++.h>

using namespace std;

int N, M, P, chan[100001];
bool visited[100001];

int main(){
    scanf("%d%d%d", &N, &M, &P);

    for (int i = 0; i <= M; i++) chan[i] = -1;

    for (int i = 0, a, b; i < N; i++){
        scanf("%d%d", &a, &b);

        if (chan[b] == -1)
            chan[b] = a;
    }

    bool flag = false;
    int cnt = 0;

    while(true){
        if (visited[P]) {
            break;
        }

        if (chan[P] == -1){
            flag = true;
            break;
        }

        visited[P] = true;

        P = chan[P];
        cnt++;
    }

    if (flag)
        cout << cnt << endl;
    else
        cout << -1 << endl;
}
