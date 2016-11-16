
#include <bits/stdc++.h>

#define MAXN 505

using namespace std;

int T, N, M, matrix[MAXN][MAXN], matching[MAXN][MAXN];

int pre[MAXN];
bool visited[MAXN];

int cnt = 1, id[MAXN], lowlink[MAXN];
bool instack[MAXN], used[MAXN];
stack<int> st;
vector<vector<int>> components;

void tarjans(int node){
    id[node] = cnt;
    lowlink[node] = cnt;
    cnt++;
    used[node] = true;

    st.push(node);
    instack[node] = true;

    for (int i = 0; i < N; i++){
        if (matrix[node][i]){
            if (id[i] == 0){
                tarjans(i);
                lowlink[node] = min(lowlink[node], lowlink[i]);
            } else if (instack[i]){
                lowlink[node] = min(lowlink[node], id[i]);
            }
        }
    }

    if (lowlink[node] == id[node]){
        vector<int> curcomp;
        while(true){
            int c = st.top();
            st.pop();
            instack[c] = false;
            curcomp.push_back(c);

            if (c == node) break;
        }

        components.push_back(curcomp);
    }
}

bool hungary(int cur){
    for (int i = 0; i < N; i++){
        if (matching[cur][i]){
            if (visited[i]) continue;
            visited[i] = true;

            if (pre[i] == -1 || hungary(pre[i])){
                pre[i] = cur;
                return true;
            }
        }
    }

    return false;
}

int main(){
    //freopen("gentrification.in", "r", stdin);

    cin >> T;
    for (int cc = 1; cc <= T; cc++){
        cnt = 0;
        memset(matrix, 0, sizeof matrix);
        memset(matching, 0, sizeof matching);
        memset(pre, 0, sizeof pre);
        memset(id, 0, sizeof id);
        memset(instack, 0, sizeof instack);
        memset(used, 0, sizeof used);
        memset(lowlink, 0, sizeof lowlink);

        components.clear();
        while(!st.empty()) st.pop();

        cin >> N >> M;
        for (int i = 0, a, b; i < M; i++){
            cin >> a >> b;
            matrix[a][b] = true;
        }

        for (int i = 0; i < N; i++){
            if (!used[i])
                tarjans(i);
        }

        for (int k = 0; k < N; k++){
            for (int i = 0; i < N; i++){
                for (int j = 0; j < N; j++){
                    if (matrix[i][k] && matrix[k][j])
                        matrix[i][j] = true;
                }
            }
        }

        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                if (matrix[i][j] && (!matrix[j][i])) matching[i][j] = true;
            }
        }

        int ans = 0;
        for (int i = 0; i < N; i++) pre[i] = -1;

        for (int i = 0; i < N; i++){
            memset(visited, 0, sizeof visited);
            hungary(i);

        }

        for (int i = 0; i < N; i++){
            if (pre[i] == -1) ans++;
        }

        printf("Case #%d: %d\n", cc, ans);
    }
}

