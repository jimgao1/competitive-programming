
#include <bits/stdc++.h>

#define MAXN 101
#define INF 0x3f3f3f3f
#define state pair<int, pair<int, int>>

using namespace std;

int N, K, speed[MAXN], dist[MAXN], matrix[MAXN][MAXN];
queue<int> q;

int main(){
    while(cin >> N >> K) {
        memset(matrix, 0x3f, sizeof matrix);
        for (int i = 0; i < N; i++) cin >> speed[i];
        string str;
        getline(cin, str);
        for (int i = 0; i < N; i++) {
            getline(cin, str);
            stringstream ss(str);
            vector<int> nodes;

            while (!ss.eof()) {
                int n;
                ss >> n;
                nodes.push_back(n);
            }

            sort(nodes.begin(), nodes.end());

            for (int j = 0; j < nodes.size(); j++) {
                for (int k = j + 1; k < nodes.size(); k++) {
                    int a = nodes[j], b = nodes[k];
                    matrix[a][b] = min(matrix[a][b], abs(b - a) * speed[i]);
                    matrix[b][a] = min(matrix[b][a], abs(b - a) * speed[i]);
                }
            }
        }

        memset(dist, 0x3f, sizeof dist);

        q.push(0);
        dist[0] = 0;

        while(!q.empty()){
            int cur = q.front();
            q.pop();

            for (int i = 0; i < MAXN; i++){
                if (dist[cur] + matrix[cur][i] + 60 < dist[i]){
                    dist[i] = dist[cur] + matrix[cur][i] + 60;
                    q.push(i);
                }
            }
        }

        if (dist[K] == INF)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << max(0, dist[K] - 60) << endl;
    }
}
