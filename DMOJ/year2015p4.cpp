
#include <bits/stdc++.h>

using namespace std;

struct state{
    string res;
    int va, vb;

    state(int a, int b, string s){
        va = a, vb = b, res = s;
    }
};

int va, vb, M;
bool visited[1001][1001];
queue<state> q;

int main(){
    scanf("%d%d%d", &va, &vb, &M);
    q.push(state(0, 0, ""));

    bool flag = false;
    while(!q.empty()){
        state cur = q.front();
        q.pop();

        if (cur.va == M || cur.vb == M){
            cout << cur.res << endl;
            flag = true;
            break;
        }

        if (visited[cur.va][cur.vb]) continue;
        visited[cur.va][cur.vb] = true;

        //fill A
        q.push(state(va, cur.vb, cur.res + "fill A\n"));
        //fill B
        q.push(state(cur.va, vb, cur.res + "fill B\n"));
        //pour A B
        if (cur.va >= vb - cur.vb){
            q.push(state(cur.va - (vb - cur.vb), vb, cur.res + "pour A B\n"));
        } else {
            q.push(state(0, cur.vb + cur.va, cur.res + "pour A B\n"));
        }
        //pour B A
        if (cur.vb >= va - cur.va){
            q.push(state(va, cur.vb - (va - cur.va), cur.res + "pour B A\n"));
        } else {
            q.push(state(cur.va + cur.vb, 0, cur.res + "pour B A\n"));
        }
        //chug A
        q.push(state(0, cur.vb, cur.res + "chug A\n"));
        //chug B
        q.push(state(cur.va, 0, cur.res + "chug B\n"));

    }

    if (!flag)
        printf("Not possible\n");
}
