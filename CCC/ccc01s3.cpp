
#include <bits/stdc++.h>

#define MAXN 30

using namespace std;

bool visited[MAXN], matrix[MAXN][MAXN];

bool test(){
    memset(visited, 0, sizeof visited);
    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        visited[cur] = true;

        if (cur == 1) return true;
        for (int i = 0; i < MAXN; i++){
            if ((matrix[cur][i] || matrix[i][cur]) && !visited[i]){
                q.push(i);
            }
        }
    }

    return false;
}

int main(){
    while(true){
        string str;
        cin >> str;
        if (str == "**") break;

        matrix[str[0] - 'A'][str[1] - 'A'] = true;
    }

    int cnt = 0;
    for (int i = 0; i < MAXN; i++){
        for (int j = 0; j < MAXN; j++){
            if (matrix[i][j]){
                matrix[i][j] = false;
                if (!test()){
                    cout << (char)(i + 'A') << (char)(j + 'A') << endl;
                    cnt++;
                }

                matrix[i][j] = true;
            }
        }
    }

    printf("There are %d disconnecting roads.\n", cnt);

}

