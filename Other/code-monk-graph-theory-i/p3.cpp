
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, D, minDep = INF;
bool matrix[10001][10001], visited[10001];

int find_connected(int node){
    //cout << "current = " << node << endl
    if (visited[node]) return 0;
    visited[node] = true;

    int sum = 0;
    for (int i = 0; i < N; i++)
        if (matrix[node][i] && !visited[i])
            sum += find_connected(i);

    return sum + 1;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    memset(matrix, false, 10001 * 10001);
    cin >> N >> D;

    for (int i = 0, x, y; i < D; i++){
        cin >> x >> y;

        matrix[x - 1][y - 1] = true; //I am so stupid
    }

    for (int i = 0; i < N; i++){
        memset(visited, false, 10001);
        int n = find_connected(i);

        if (n != 0)
            minDep = min(minDep, n);
    }

    cout << minDep << endl;

    return 0;
}
