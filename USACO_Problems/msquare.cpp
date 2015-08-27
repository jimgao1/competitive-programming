/*
ID: jim_yub1
LANG: C++11
TASK: msquare
*/

#include <bits/stdc++.h>

using namespace std;

queue<pair<string, int>> bfs;
queue<string> steps;

unordered_map<string, bool> visited;

string transformA(string state){
    stringstream ss;
    ss << state[4] << state[5] << state[6] << state[7] << state[0] << state[1] << state[2] << state[3];

    return ss.str();
}

string transformB(string state){
    stringstream ss;
    ss << state[3] << state[0] << state[1] << state[2] << state[7] << state[4] << state[5] << state[6];

    return ss.str();
}

string transformC(string state){
    stringstream ss;
    ss << state[0] << state[5] << state[1] << state[3] << state[4] << state[6] << state[2] << state[7];

    return ss.str();
}

int main(){
    freopen("msquare.in", "r", stdin);
    freopen("msquare.out", "w", stdout);

    stringstream sfinal;
    for (int i = 0, x; i < 8; i++){
        scanf("%d", &x);
        sfinal << x;
    }

    string final = sfinal.str();
    reverse(final.begin() + 4, final.begin() + 8);

    bfs.push({"12348765", 0});
    steps.push("");

    while(!bfs.empty()){
        string current = bfs.front().first;
        int curSteps = bfs.front().second;

        string cs = steps.front();

        bfs.pop();
        steps.pop();

        if (visited[current]) continue;
        visited[current] = true;

        if (current == final){
            printf("%d\n", curSteps);
            cout << cs << endl;
            return 0;
        }

        bfs.push({transformA(current), curSteps + 1});
        bfs.push({transformB(current), curSteps + 1});
        bfs.push({transformC(current), curSteps + 1});

        steps.push(cs + "A");
        steps.push(cs + "B");
        steps.push(cs + "C");
    }
}
