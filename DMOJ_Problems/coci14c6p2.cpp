
#include <bits/stdc++.h>

using namespace std;

int N, M, place[11][3], cur[3];
bool av[23][3];

bool dfs(int idx){
    if (cur[0] == 0 && cur[1] == 0 && cur[2] == 0) return true;
    if (idx == M) return false;

    for (int i = 0; i < 3; i++){
        if (av[idx][i] && cur[i] > 0){
            cur[i] -= 1;
            if (dfs(idx + 1)) return true;
            cur[i] += 1;
        }
    }

    if (dfs(idx + 1)) return true;
    return false;
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        string str;
        cin >> str;

        place[i][0] = atoi(str.substr(0, str.find("-")).c_str());
        str = str.substr(str.find("-") + 1);
        place[i][1] = atoi(str.substr(0, str.find("-")).c_str());
        str = str.substr(str.find("-") + 1);
        place[i][2] = atoi(str.substr(0, str.find("-")).c_str());
    }

    cin >> M;
    for (int i = 0; i < M; i++){
        string str;
        cin >> str;

        for (int j = 0; j < str.length(); j++){
            if (str[j] == 'O'){
                av[i][0] = true;
            } else if (str[j] == 'V'){
                av[i][1] = true;
            } else if (str[j] == 'N'){
                av[i][2] = true;
            }
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < 3; j++){
            cur[j] = place[i][j];
        }

        if (dfs(0))
            cout << "DA" << endl;
        else
            cout << "NE" << endl;
    }
}
