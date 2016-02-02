
#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> names;
unordered_set<string> occ;

int N, M, ca = 0;
bool fir = false, conn[30][30], visited[30];

vector<int> adjList[31];

string dict[30];

void dfs(int src, int cur){
    conn[src][cur] = true;

    for (int i : adjList[cur])
        if (!conn[src][i])
            dfs(src, i);
}

int main(){

    cin.sync_with_stdio(0);
    cin.tie(0);

    while(true){
        memset(conn, 0, sizeof conn);
        memset(visited, 0, sizeof visited);

        for (int i = 0; i < 30; i++) adjList[i].clear();
        names.clear();
        occ.clear();

        int cnt = 0;
        cin >> N >> M;

        if (N == 0 && M == 0) break;

        if (fir){
            cout << endl;
        }

        fir = true;

        for (int i = 0; i < M; i++){
            string n1, n2;
            cin >> n1 >> n2;

            if (occ.find(n1) == occ.end()){
                names[n1] = cnt++;
                occ.insert(n1);
                dict[names[n1]] = n1;
            }

            if (occ.find(n2) == occ.end()){
                names[n2] = cnt++;
                occ.insert(n2);
                dict[names[n2]] = n2;
            }

            adjList[names[n1]].push_back(names[n2]);
        }

        for (int i = 0; i < N; i++) dfs(i, i);

        cout << "Calling circles for data set " << (++ca) << ":" << endl;

        for (int i = 0; i < N; i++){
            if (!visited[i]){
                cout << dict[i];
                visited[i] = true;

                for (int j = 0; j < N; j++){
                    if ((!visited[j]) && conn[i][j] && conn[j][i]){
                        cout << ", " << dict[j];
                        visited[j] = true;
                    }
                }

                cout << endl;
            }
        }
    }
}
