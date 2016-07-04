
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int T;
vector<string> words;
unordered_map<string, vector<string>> adjList;

int calc(string src, string tar){
    queue<pair<string, int>> q;
    unordered_map<string, bool> visited;
    q.push({src, 0});

    while(!q.empty()){
        string cur = q.front().first;
        int st = q.front().second;
        q.pop();

        if (visited[cur]) continue;
        visited[cur] = true;

        if (cur == tar) return st;

        for (string nxt : adjList[cur]){
            q.push({nxt, st + 1});
        }
    }

    return INF;
}

int main(){
    cin >> T;
    string temp;
    getline(cin, temp);
    getline(cin, temp);

    bool f = false;

    while(T--) {
        words.clear();
        adjList.clear();

        if (f) cout << endl;
        f = true;

        while (true) {
            string str;
            getline(cin, str);
            if (str == "*") break;
            words.push_back(str);
        }

        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (words[i].size() == words[j].size()) {
                    int cnt = 0;
                    for (int k = 0; k < words[i].size(); k++)
                        if (words[i][k] != words[j][k])
                            cnt++;

                    if (cnt == 1) {
                        adjList[words[i]].push_back(words[j]);
                        adjList[words[j]].push_back(words[i]);
                    }
                }
            }
        }

        while (true) {
            string line, sa, sb;
            getline(cin, line);
            if (line.size() == 0) break;
            stringstream ss(line);
            ss >> sa >> sb;
            int fuckyou = calc(sa, sb);

            cout << sa << " " << sb << " " << (fuckyou == INF ? -1 : fuckyou) << endl;
        }

    }
}
