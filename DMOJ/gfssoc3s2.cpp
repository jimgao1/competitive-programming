
#include <bits/stdc++.h>

using namespace std;

struct state{
    int pr, pc, br, bc, steps;
    state(int a, int b, int c, int d, int e){
        pr = a, pc = b, br = c, bc = d, steps = e;
    }
};

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int R, C, playerR, playerC, boxR, boxC, targetR, targetC;
char grid[31][31];
bool visited[31][31][31][31];
queue<state> q;

int main(){
    cin >> R >> C;
    for (int i = 0; i < R; i++){
        string line;
        cin >> line;

        for (int j = 0; j < C; j++){
            grid[i][j] = line[j];

            if (grid[i][j] == 'P'){
                playerR = i, playerC = j;
            } else if (grid[i][j] == 'B'){
                boxR = i, boxC = j;
            } else if (grid[i][j] == 'X'){
                targetR = i, targetC = j;
            }
        }
    }

    q.push(state(playerR, playerC, boxR, boxC, 0));

    bool flag = false;

    while(!q.empty()){
        state cur = q.front();
        q.pop();

        if (cur.br == targetR && cur.bc == targetC){
            cout << cur.steps << endl;
            flag = true;
            break;
        }

        if (visited[cur.pr][cur.pc][cur.br][cur.bc]) continue;
        visited[cur.pr][cur.pc][cur.br][cur.bc] = true;

        for (int i = 0; i < 4; i++){
            int nr = cur.pr + dx[i], nc = cur.pc + dy[i];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (grid[nr][nc] == '#') continue;

            //detect box push
            if (cur.br == nr && cur.bc == nc){
                int nbr = cur.br + dx[i], nbc = cur.bc + dy[i];
                if (nbr < 0 || nbr >= R || nbc < 0 || nbc >= C) continue;
                if (grid[nbr][nbc] == '#') continue;

                q.push(state(nr, nc, nbr, nbc, cur.steps + 1));
            } else {
                q.push(state(nr, nc, cur.br, cur.bc, cur.steps + 1));
            }
        }
    }

    if (!flag)
        cout << "-1" << endl;
    
}
