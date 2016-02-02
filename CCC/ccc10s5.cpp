
#include<bits/stdc++.h>
using namespace std;

#define MAXN 100
#define MAXX 2501

int tree[MAXN*4];

int dpLeft[MAXN * 4][2501], dpRight[MAXN * 4][2501], dp[MAXN * 4][2501];

int pos = 0;
char c;
int X;
string line;

void read(){
    c = line[pos];
    pos++;
    while(isspace(c)){
        c = line[pos];
        pos++;
    }
}

bool isnum(){
    return(c >= '0' && c <= '9');
}

void build(int index){
    read();
    if(isnum()){
        int v = c - '0';
        c = line[pos];
        pos++;
        while(isnum()){
            v*=10;
            v += c-'0';
            c = line[pos];
            pos++;
        }
        pos--;
        tree[index] = v;
        return;
    }
    else if(c == '('){
        build(index*2);
        build(index*2+1);
        read();
    }
}

void dfs(int index){
    //printf("index = %d\n", index);

    if (tree[index] == 0){
        dfs(index * 2);
        dfs(index * 2 + 1);

        //dp left
        for (int i = 0; i <= X; i++){
            //dpLeft[index][i] = 0;
            for (int j = 0; j <= i; j++){
                //left branch: j, left node: i - j
                dpLeft[index][i] = max(dpLeft[index][i], min((1 + j) * (1 + j), dp[index * 2][i - j]));
            }
        }

        //dp right
        for (int i = 0; i <= X; i++){
            //dpRight[index][i] = 0;
            for (int j = 0; j <= i; j++){
                dpRight[index][i] = max(dpRight[index][i], min((1 + j) * (1 + j), dp[index * 2 + 1][i - j]));
            }
        }

        //dp
        for (int i = 0; i <= X; i++){
            //dp[index][i] = 0;
            for (int j = 0; j <= i; j++){
                //left branch: j, right branch: i - j
                dp[index][i] = max(dp[index][i], dpLeft[index][j] + dpRight[index][i - j]);
            }
        }
    } else {
        for (int i = 0; i <= X; i++){
            dp[index][i] = tree[index] + i;
        }
    }


}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    getline(cin, line);
    build(1);
    cin >> X;

    memset(dp, 0, sizeof dp);
    memset(dpLeft, 0, sizeof dpLeft);
    memset(dpRight, 0, sizeof dpRight);

    dfs(1);
    cout << dp[1][X] << endl;
}
