
#include <bits/stdc++.h>

#define MAXN 10001

using namespace std;

/*
    In a SCC, every node is accessible by any other node

    Tarjan's algorithm trys to find the root of each component
    The "root" is the first node encountered during DFS.

    ID: the order where the node is visited during DFS
    Lowlink: What is the ancestor with the lowest order ID

    The root is determined when lowlink == id
*/

int N, M, cnt = 1, id[MAXN], lowlink[MAXN];
bool instack[MAXN];

stack<int> st;
vector<int> adjList[MAXN];
vector<vector<int>> components;

void tarjans(int node){
    id[node] = cnt;
    lowlink[node] = cnt;
    cnt++;

    st.push(node);
    instack[node] = true;

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
    for (int i = 0, a, b; i < M; i++){
        cin >> a >> b;
        adjList[a - 1].push_back(b - 1);
    }

    tarjans(0);

    for (vector<int> s : components){
        for (int n : s)
            printf("%d ", n + 1);
        printf("\n");
    }
}

