/*
ID: jim.yub1
LANG: C++11
TASK: heritage
*/

#include <bits/stdc++.h>

using namespace std;

struct treenode{
    char name;
    treenode* leftChild;
    treenode* rightChild;
};

treenode* root = NULL;

treenode* createNode(){
    return new treenode();
}

treenode* buildTree(treenode* current, string preorder, string inorder){
    if (preorder.length() == 0 || inorder.length() == 0){
        return NULL;
    }

    if (preorder.length() != inorder.length()) return NULL;
    current = createNode();

    current->name = preorder[0];

    if (preorder.length() == 1 || inorder.length() == 1) return current;

    int preorderIndex = -1;
    for (int i = 0; i < inorder.length(); i++) if (inorder[i] == preorder[0]) preorderIndex = i;
    preorder.erase(preorder.begin());

    string inorderLeft = inorder.substr(0, preorderIndex);
    string inorderRight = inorder.substr(preorderIndex + 1);

    string preorderLeft = preorder.substr(0, preorderIndex);
    string preorderRight = preorder.substr(inorderLeft.length());

    current->leftChild = buildTree(current->leftChild, preorderLeft, inorderLeft);
    current->rightChild = buildTree(current->rightChild, preorderRight, inorderRight);

    return current;
}

void postOrder(treenode* node){
    if (node == NULL) {
        return;
    }

    postOrder(node->leftChild);
    postOrder(node->rightChild);
    if (node->name >= 'A' && node->name <= 'Z')
        cout << node->name;
}

int main(){
    freopen("heritage.in", "r", stdin);
    freopen("heritage.out", "w", stdout);

    string preorder, inorder;
    cin >> inorder >> preorder;

    root = buildTree(root, preorder, inorder);
    postOrder(root);
    cout << endl;

}
