#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int tree[400000];
int data[100000];

void build_tree(int index, int tStart, int tEnd){
    if (tStart == tEnd){
        tree[index] = data[tStart];
        return;
    }

    int mid = (tStart + tEnd) / 2;

    build_tree(index * 2, tStart, mid);
    build_tree(index * 2 + 1, mid + 1, tEnd);

    tree[index] = min(tree[index * 2], tree[index * 2 + 1]);

    return;
}

void update_tree(int index, int tStart, int tEnd, int id, int newData){
    if (tStart == tEnd){
        tree[index] = newData;
        return;
    }

    int mid = (tStart + tEnd) / 2;

    if (id <= mid)
        update_tree(index * 2, tStart, mid, id, newData);
    else
        update_tree(index * 2 + 1, mid + 1, tEnd, id, newData);

    tree[index] = min(tree[index * 2], tree[index * 2 + 1]);

    return;
}

int get_min(int index, int tStart, int tEnd, int qStart, int qEnd){
    if (tStart > qEnd || tEnd < qStart) return 1000002;
    if (qStart <= tStart && qEnd >= tEnd) return tree[index];

    int mid = (tStart + tEnd) / 2;

    return min(get_min(index * 2, tStart, mid, qStart, qEnd),
               get_min(index * 2 + 1, mid + 1, tEnd, qStart, qEnd));
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int nodeCount, inquiryCount;
    cin >> nodeCount >> inquiryCount;

    for (int i=0; i<nodeCount; i++){
        cin >> data[i];
    }

    build_tree(1, 0, nodeCount - 1);

    for (int i=0; i<inquiryCount; i++){
        string command;
        int a, b;

        cin >> command >> a >> b;

        if (command == "Q"){
            int result = get_min(1, 0, nodeCount - 1, a, b);
            cout << result << "\n";
        } else {
            update_tree(1, 0, nodeCount - 1, a, b);
        }
    }
}
