
#include <bits/stdc++.h>

using namespace std;

int T, E, cnt = 0;
bool visited[100001];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    while(T-- != 0){
        cin >> E;
        cnt = 0;

        for (int i = 0; i < 100001; i++) visited[i] = false;

        for (int i = 0, x, y; i < E; i++){
            cin >> x >> y;

            visited[x] = true, visited[y] = true;
        }

        for (int i = 0; i < 100001; i++)
            if (visited[i]) cnt++;

        cout << cnt << endl;
    }
}
