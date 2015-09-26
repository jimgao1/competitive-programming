
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define endl "\n"

using namespace std;

int N, M, R;
bool solution = false, used[30], matrix[30][30], indeg[30], visited[30];
char revdict[30];
map<char, int> dict;
string curline;

string getline_util(){
    string line;
    while(true){
        getline(cin, line);
        if (line.length() != 0) return line;
    }
}

void dfs(string order){
    bool flag = true;
    for (int i = 0; i < M; i++) flag = flag & visited[i];

    if (flag) {
        cout << order[0];
        for (int i = 1; i < order.length(); i++)
            cout << " " << order[i];
        cout << endl;

        solution = true;
        return;
    }

    for (int i = 0; i < M; i++){
        if (!visited[i]){
            int cnt = 0;
            for (int j = 0; j < M; j++){
                if (!visited[j] && matrix[j][i]) cnt++;
            }

            if (cnt == 0){
                visited[i] = true;
                dfs(order + revdict[i]);
                visited[i] = false;
            }
        }
    }
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin.sync_with_stdio(0);
    //cin.tie(0);

    scanf("%d", &N);

    while(N--){
        //initialization
        memset(used, 0, sizeof used);
        memset(matrix, 0, sizeof matrix);
        memset(indeg, 0, sizeof indeg);
        solution = false;
        dict.clear();

        //get list of variables
        curline = getline_util();
        M = (curline.length() + 1) / 2;
        for (int i = 0; i < M; i++){
            dict[curline[2 * i]] = i;
            revdict[i] = curline[2 * i];
        }

        //get list of relations
        curline = getline_util();
        R = (curline.length() + 1) / 4;
        for (int i = 0; i < R; i++){
            char na = curline[i * 4];
            char nb = curline[i * 4 + 2];

            matrix[dict[na]][dict[nb]] = true;
            indeg[dict[nb]] ++;
        }

        dfs("");

        if (!solution) cout << "NO" << endl;
        if (N != 0) cout << endl;
    }
}
