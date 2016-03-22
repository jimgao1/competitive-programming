
#include <bits/stdc++.h>

using namespace std;

int T, N;

vector<int> adjList[10001];

map<string, int> dict;

int dfs(int cur, int pre){
    int ans = 1;
    for (int i : adjList[cur]){
        if (i != pre){
            ans = max(ans, dfs(i, cur) + 1);
        }
    }

    return ans;
}

string toLowerCase(string str){
    for (int i = 0; i < str.size(); i++){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = 'a' + (str[i] - 'A');
        }
    }

    return str;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while(T--){
        dict.clear();
        for (int i = 0; i < 10001; i++) adjList[i].clear();

        int cnt = 0, root;
        cin >> N;

        for (int i = 0; i < N / 2; i++){
            string a, b;
            cin >> a >> b;

            if (dict.find(a) == dict.end()){
                dict[a] = cnt++;
            }

            if (dict.find(b) == dict.end()){
                dict[b] = cnt++;
            }

            adjList[dict[a]].push_back(dict[b]);
            adjList[dict[b]].push_back(dict[a]);

            if (i == N / 2 - 1) root = dict[b];
        }


        printf("%d\n", N * 10 - (dfs(root, -1) - 1) * 20);
    }
}
