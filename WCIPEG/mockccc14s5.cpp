
#include <bits/stdc++.h>

#define MAXN 210

using namespace std;

int N, M, pre[MAXN], a[MAXN], b[MAXN];
bool visited[MAXN], matrix[MAXN][MAXN];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool hungary(int cur){
    for (int i = 0; i < M; i++){
        if (!matrix[cur][i]) continue;
        if (visited[i]) continue;
        visited[i] = true;

        if (pre[i] == -1 || hungary(pre[i])){
            pre[i] = cur;
            return true;
        }
    }
    return false;
}

int main(){
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < M; i++) cin >> b[i];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (gcd(a[i], b[j]) > 1){
                matrix[i][j] = true;
            }
        }
    }

    for (int i = 0; i < M; i++){
        pre[i] = -1;
    }

    int ans = 0;
    for (int i = 0; i < N; i++){
        memset(visited, 0, sizeof visited);
        if (hungary(i)) ans++;
    }

    cout << ans * 2 << endl;
}
