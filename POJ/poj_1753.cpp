[A
#include <iostream>
#include <queue>
#include <string>

#define MAXN 16
#define pii pair<int, int>

using namespace std;

inline bool getBit(int n, int idx) { return n & (1 << idx); }
inline int setBit(int n, int idx) { return n | (1 << idx); }
inline int toggleBit(int n, int idx) { return n ^ (1 << idx); }

int fuck(int n, int r, int c){
    n = toggleBit(n, r * 4 + c);
    if (r > 0) n = toggleBit(n, (r - 1) * 4 + c);
    if (r < 3) n = toggleBit(n, (r + 1) * 4 + c);
    if (c > 0) n = toggleBit(n, r * 4 + c - 1);
    if (c < 3) n = toggleBit(n, r * 4 + c + 1);
    return n;
}

int init;
bool visited[(1 << 17)];
queue<pair<int, int> > q;

int main(){
    for (int i = 0; i < 4; i++){
        string line;
        cin >> line;
        for (int j = 0; j < 4; j++){
            if (line[j] == 'b'){
                init = setBit(init, i * 4 + j);
            }
        }
    }

    q.push(make_pair(init, 0));
    visited[init] = 1;
    while(!q.empty()){
        int cur = q.front().first, st = q.front().second;
        q.pop();

        if (cur == 0 || cur == (1 << 16) - 1){
            cout << st << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                int nxt = fuck(cur, i, j);
                if (!visited[nxt]){
                    visited[nxt] = 1;
                    q.push(make_pair(nxt, st + 1));
                }
            }
        }
    }

    cout << "Impossible" << endl;
}
