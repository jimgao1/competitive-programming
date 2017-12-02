
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int N, M, data[1 << 21], tree[1 << 21];
int wins[1 << 21];

unordered_map<int, int> rev;

void build_tree(int index, int tStart, int tEnd){
    if (tStart == tEnd){
        tree[index] = data[tStart];
        return;
    }

    int mid = (tStart + tEnd) / 2;

    build_tree(index * 2, tStart, mid);
    build_tree(index * 2 + 1, mid + 1, tEnd);

    tree[index] = max(tree[index * 2], tree[index * 2 + 1]);
    wins[rev[tree[index]]] ++;

    return;
}

void update_tree(int index, int tStart, int tEnd, int id, int newData){
    if (tStart == tEnd){
        tree[index] = newData;
        return;
    }

    int mid = (tStart + tEnd) / 2;
    wins[rev[tree[index]]] --;

    if (id <= mid)
        update_tree(index * 2, tStart, mid, id, newData);
    else
        update_tree(index * 2 + 1, mid + 1, tEnd, id, newData);

    tree[index] = max(tree[index * 2], tree[index * 2 + 1]);
    wins[rev[tree[index]]] ++;

    return;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= (1 << N); i++) {
        cin >> data[i];
        rev[data[i]] = i;
    }

    build_tree(1, 1, (1 << N));

    for (int i = 0; i < M; i++){
        char cmd;
        int a, b;

        cin >> cmd;

        if (cmd == 'R'){
            cin >> a >> b;
            rev[b] = a;
            data[a] = b;
            update_tree(1, 0, (1 << N), a, b);
        } else if (cmd == 'W'){
            cout << rev[tree[1]] << "\n";
        } else if (cmd == 'S'){
            cin >> a;
            cout << wins[a] << "\n";
        }
    }
}
