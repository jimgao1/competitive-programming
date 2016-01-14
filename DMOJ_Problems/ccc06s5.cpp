
#include <bits/stdc++.h>

using namespace std;

inline bool getBit(int n, int idx) { return n & (1 << idx); }
inline int setBit(int n, int idx) { return n | (1 << idx); }
inline int clearBit(int n, int idx) { return n & ~(1 << idx); }

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int M, N, A, B, C, init;
vector<int> nxt[(1 << 21)];
bool cur[5][5], snxt[5][5], eden[(1 << 21)], visited[(1 << 21)];
queue<pair<int, int>> q;

inline int id(int m, int n) { return m * N + n; }

void print(int st){
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            if (getBit(st, id(i, j)))
                printf("*");
            else
                printf(".");
        }
        printf("\n");
    }
}

int main(){
    cin >> M >> N >> A >> B >> C;

    for (int i = 0; i < M; i++){
        string line;
        cin >> line;
        for (int j = 0; j < N; j++){
            if (line[j] == '*')
                init = setBit(init, id(i, j));
        }
    }

    for (int st = 0; st < (1 << (M * N)); st++){
        memset(cur, 0, sizeof cur);
        memset(snxt, 0, sizeof snxt);

        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                if (getBit(st, id(i, j))){
                    cur[i][j] = true;
                }
            }
        }

        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                int cnt = 0;
                for (int k = 0; k < 8; k++){
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                    if (cur[nx][ny]) cnt++;
                }

                if (cur[i][j]){
                    if (cnt < A || cnt > B){
                        snxt[i][j] = false;
                    } else {
                        snxt[i][j] = true;
                    }
                } else {
                    if (cnt > C){
                        snxt[i][j] = true;
                    } else {
                        snxt[i][j] = false;
                    }
                }
            }
        }

        int n = 0;
        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                if (snxt[i][j])
                    n = setBit(n, id(i, j));
            }
        }

        if (n == st)
            eden[st] = true;
        else
            nxt[n].push_back(st);
    }

    bool flag = false;
    q.push({init, 0});
    while(!q.empty()){
        int cur = q.front().first, st = q.front().second;
        q.pop();

        if (nxt[cur].size() == 0){
            printf("%d\n", st);
            flag = true;
            break;
        }

        if (visited[cur]) continue;
        visited[cur] = true;

        for (int c : nxt[cur]){
            q.push({c, st + 1});
        }
    }

    if (!flag)
        printf("-1\n");
}

