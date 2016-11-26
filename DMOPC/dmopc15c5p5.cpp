
#include <bits/stdc++.h>

#define MAXN 250001
#define ll long long
#define MOD 1000000007

using namespace std;

int N, par[MAXN], order[MAXN], ans[MAXN];
ll bit[MAXN];
vector<int> adjList[MAXN];

void add(int i, int val){
    while(i <= MAXN){
        bit[i] += val;
        bit[i] = bit[i];
        i += (i & -i);
    }
}

ll query(int i){
    ll sum = 0;
    while(i > 0){
        sum += bit[i];
        sum = sum % MOD;
        i -= (i & -i);
    }
    return sum % MOD;
}

void dfs(int cur){
    ll old = query(order[cur]);
    for (int i : adjList[cur]){
        dfs(i);
    }

    ans[cur] = query(order[cur]) - old + 1;
    ans[cur] = (ans[cur] + MOD) % MOD;
    add(order[cur], ans[cur]);
}

int main(){
    scanf("%d", &N);
    for (int i = 0; i <= MAXN; i++) {
        ans[i] = 1;
    }
    int root = -1;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &par[i]);
        if (par[i] == 0){
            root = i;
        } else {
            adjList[par[i]].push_back(i);
        }
    }

    for (int i = 1; i <= N; i++) {
        int x;
        scanf("%d", &x);
        order[x] = i;
    }

    dfs(root);

    for (int i = 1; i <= N; i++){
        printf("%d ", ans[i] % MOD);
    }
    printf("\n");
}

#include <bits/stdc++.h>

#define MAXN 250001
#define ll long long
#define MOD 1000000007

using namespace std;

int N, par[MAXN], order[MAXN], ans[MAXN];
ll bit[MAXN];
vector<int> adjList[MAXN];

void add(int i, int val){
    while(i <= MAXN){
        bit[i] += val;
        bit[i] = bit[i];
        i += (i & -i);
    }
}

ll query(int i){
    ll sum = 0;
    while(i > 0){
        sum += bit[i];
        sum = sum % MOD;
        i -= (i & -i);
    }
    return sum % MOD;
}

void dfs(int cur){
    ll old = query(order[cur]);
    for (int i : adjList[cur]){
        dfs(i);
    }

    ans[cur] = query(order[cur]) - old + 1;
    ans[cur] = (ans[cur] + MOD) % MOD;
    add(order[cur], ans[cur]);
}

int main(){
    scanf("%d", &N);
    for (int i = 0; i <= MAXN; i++) {
        ans[i] = 1;
    }
    int root = -1;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &par[i]);
        if (par[i] == 0){
            root = i;
        } else {
            adjList[par[i]].push_back(i);
        }
    }

    for (int i = 1; i <= N; i++) {
        int x;
        scanf("%d", &x);
        order[x] = i;
    }

    dfs(root);

    for (int i = 1; i <= N; i++){
        printf("%d ", ans[i] % MOD);
    }
    printf("\n");
}

