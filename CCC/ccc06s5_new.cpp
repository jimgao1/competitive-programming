
#include <bits/stdc++.h>

using namespace std;

inline bool getBit(int n, int idx) { return n & (1 << idx); }
inline int setBit(int n, int idx) { return n | (1 << idx); }
inline int clearBit(int n, int idx) { return n & ~(1 << idx); }

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

int M, N, A, B, C;
bool visited[(1 << 20)];
vector<int> adjList[(1 << 20)];

queue<pair<int, int>> q;

inline int id(int r, int c) { return r * N + c; }

int main(){
    cin >> M >> N >> A >> B >> C;

    int init = 0;
    for (int i = 0; i < M; i++){
        string line;
        cin >> line;
        for (int j = 0; j < N; j++){
            if (line[j] == '*')
                init = setBit(init, id(i, j));
        }
    }

    for (int st = 0; st < (1 << (M * N)); st++){
        int next = st;
        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                int cnt = 0;
                for (int k = 0; k < 8; k++){
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

                    if (getBit(st, id(nx, ny))) cnt++;
                }

                if (getBit(st, id(i, j))){
                    if (cnt < A || cnt > B){
                        next = clearBit(next, id(i, j));
                    }
                } else {
                    if (cnt > C){
                        next = setBit(next, id(i, j));
                    }
                }
            }
        }

        if (next != st){
            adjList[next].push_back(st);
        }
    }

    int ans = -1;

    q.push({init, 0});
    while(!q.empty()){
        int cur = q.front().first, st = q.front().second;
        q.pop();

        if (visited[cur]) continue;
        visited[cur] = true;

        if (adjList[cur].size() == 0){
            ans = st;
            break;
        }

        for (int i : adjList[cur]){
            q.push({i, st + 1});
        }
    }

    printf("%d\n", ans);
}
