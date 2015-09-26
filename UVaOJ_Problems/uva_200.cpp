
#include <bits/stdc++.h>

using namespace std;

bool flag = false, used[30], matrix[30][30], visited[30];
vector<string> seq;
vector<int> result, ideg;
string x;

int main(){
    while(!cin.eof()){
        if (flag) cout << endl;
        flag = true;

        seq.clear();
        result.clear();
        ideg.clear();
        memset(used, 0, sizeof used);
        memset(matrix, 0, sizeof matrix);
        memset(visited, 0, sizeof visited);

        while(true){
            cin >> x;
            for (int i = 0; i < x.length(); i++)
                used[x[i] - 'A'] = true;
            if (x == "#") break;
            seq.push_back(x);
        }

        for (int i = 0; i < seq.size(); i++){
            for (int j = 0; j < i; j++){
                int idx = -1;
                for (int k = 0; k < min(seq[i].length(), seq[j].length()); k++){
                    if (seq[i][k] != seq[j][k]){
                        idx = k;
                        break;
                    }
                }

                if (idx >= seq[i].length() || idx >= seq[j].length()) continue;
                if (idx == -1) continue;

                matrix[seq[i][idx] - 'A'][seq[j][idx] - 'A'] = true;
            }
        }

        while(true){
            bool flag = true;
            for (int i = 0; i < 26; i++)
                flag = flag & visited[i];

            if (flag) break;

            ideg.clear();

            for (int i = 0; i < 26; i++){
                if (!visited[i]){
                    int indegree = 0;

                    for (int j = 0; j < 26; j++){
                        if (!visited[j] && matrix[j][i]) indegree ++;
                    }

                    if (indegree == 0) ideg.push_back(i);
                }
            }

            if (ideg.empty()) break;

            for (int cur : ideg){
                visited[cur] = true;

                for (int i = 0; i < 26; i++){
                    matrix[cur][i] = false;
                    matrix[i][cur] = false;
                }

                result.push_back(cur);
            }
        }

        reverse(result.begin(), result.end());
        for (int c : result){
            if (used[c])
                cout << (char)(c + 'A');
        }
    }
}
