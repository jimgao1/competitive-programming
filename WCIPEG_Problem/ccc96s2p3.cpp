
#include <bits/stdc++.h>

#define MAXN 2048

using namespace std;

struct node{
    char value;
    int depth;

    node(){
        value = 'e';
        depth = 0;
    }

    node(char a, int b){
        value = a, depth = b;
    }
};

node tree[MAXN];
queue<char> stream;

void insert_node(int cur){
    if (stream.empty()) return;
    if (cur >= MAXN) return;

    char c = stream.front();
    stream.pop();

    if (c == 'f'){
        tree[cur].value = c;
    } else if (c == 'p'){
        if (tree[cur].value == 'e'){
            tree[cur].value = c;
        }
    }

    if (c == 'p'){
        for (int i = 0; i < 4; i++){
            tree[cur * 4 + i].depth = tree[cur].depth + 1;
            insert_node(cur * 4 + i);
        }
    }
}

void print_tree(int cur){
    if (cur >= MAXN) return;

    printf("id = %d, value = %c, depth = %d\n", cur, tree[cur].value, tree[cur].depth);
    if (tree[cur].value == 'p'){
        printf("entering partial\n");
        for (int i = 0; i < 4; i++)
            print_tree(cur * 4 + i);
        printf("exiting partial\n");
    }
}

int count_black(int cur){
    if (cur >= MAXN) return 0;

    if (tree[cur].value == 'f'){
        return pow(4, 5 - tree[cur].depth);
    } else if (tree[cur].value == 'e'){
        return 0;
    } else {
        int ans = 0;
        for (int i = 0; i < 4; i++)
            ans += count_black(cur * 4 + i);

        return ans;
    }
}

void init(){
    for (int i = 0; i < MAXN; i++){
        tree[i] = node();
    }
}

int main(){
    freopen("input.txt", "r", stdin);

    int T;
    cin >> T;

    while(T--){
        init();
        while(!stream.empty()) stream.pop();

        string str;

        cin >> str;
        for (char c : str) stream.push(c);
        insert_node(1);

        while(!stream.empty()) stream.pop();

        cin >> str;
        for (char c : str) stream.push(c);
        insert_node(1);

        printf("There are %d black pixels.\n", count_black(1));
    }
}
