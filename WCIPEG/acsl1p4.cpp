
#include <bits/stdc++.h>

#define MAXN 10001

using namespace std;

int N, M, cnt = 1, id[MAXN], lowlink[MAXN];
bool instack[MAXN], visited[MAXN];

stack<int> st;
vector<int> adjList[MAXN];
vector<vector<int>> components;

void tarjans(int node){
    id[node] = cnt;
    lowlink[node] = cnt;
    cnt++;

    st.push(node);
    instack[node] = true;

    visited[node] = true;

    for (int i : adjList[node]){
        if (id[i] == 0){
            tarjans(i);
            lowlink[node] = min(lowlink[node], lowlink[i]);
        } else if (instack[i]){
            lowlink[node] = min(lowlink[node], id[i]);
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

int main(){
    cin >> N >> M;
    for (int i = 0, a, b, c, d; i < M; i++){
        cin >> a >> b >> c >> d;
        a--, b--;
        if (c > d){
            adjList[a].push_back(b);
        } else if (c < d){
            adjList[b].push_back(a);
        }
    }

    for (int i = 0; i < N; i++){
        if (!visited[i]) tarjans(i);
    }

    int fuck = 0;
    for (vector<int> i : components){
        if (i.size() > 1) fuck += i.size();
    }

    cout << fuck << endl;
}

