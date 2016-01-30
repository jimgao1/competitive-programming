
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <utility>
#include <string>
#include <queue>

using namespace std;

int N, ans = -1;
bool visited[10000];
string sa, sb;
queue<pair<string, int>> q;

int main(){
    cin >> N;
    while(N--){
        memset(visited, 0, sizeof visited);

        ans = -1;
        while(!q.empty()) q.pop();

        cin >> sa >> sb;
        q.push({sa, 0});

        while(!q.empty()){
            string cur = q.front().first;
            int st = q.front().second;
            q.pop();

            if (cur == sb){
                ans = st;
                break;
            }

            if (visited[atoi(cur.c_str())]) continue;
            visited[atoi(cur.c_str())] = true;

            for (int i = 0; i < cur.size(); i++){
                string next = cur;
                next[i] ++;
                if (next[i] > '9'){
                    next[i] = '1';
                }

                q.push({next, st + 1});
            }

            for (int i = 0; i < cur.size(); i++){
                string next = cur;
                next[i] --;
                if (next[i] < '1'){
                    next[i] = '9';
                }

                q.push({next, st + 1});
            }

            for (int i = 0; i < cur.size() - 1; i++){
                string next = cur;
                swap(next[i], next[i + 1]);

                q.push({next, st + 1});
            }
        }

        cout << ans << endl;
    }
}
