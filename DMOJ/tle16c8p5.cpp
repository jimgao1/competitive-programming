#include <bits/stdc++.h>

#define MAXN 201

using namespace std;

int A, B, N, asdf = 0, pre[MAXN];
bool visited[MAXN], liked[MAXN];
vector<int> adjList[MAXN];

bool hungary(int cur){
    for (int i : adjList[cur]){
        if (visited[i]) continue;
        visited[i] = true;

        if (!pre[i] || hungary(pre[i])){
            pre[i] = cur;
            return true;
        }
    }
    return false;
}

int main(){
    cin >> A >> B;
    N = A + B;

    for (int i = 0, cnt; i < A; i++){
        cin >> cnt;
        for (int j = 0, x; j < cnt; j++){
            cin >> x;
            if (i == 0){
                liked[A + x - 1] = 1;
                asdf++;
                //adjList[i].push_back(A + x - 1);
            } else if (liked[A + x - 1]){
                adjList[i].push_back(A + x - 1);
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++){
        memset(visited, 0, sizeof visited);
        if (hungary(i)) cnt++;
    }

    cout << (asdf - cnt) << endl;
}
