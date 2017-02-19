#include <bits/stdc++.h>

#define MAXN 200010
#define INF 0x3f3f3f3f
#define pii pair<int, int>

using namespace std;

struct edge{
    int src, tar, weight;
    edge(int a, int b, int c){
        src = a, tar = b, weight = c;
    }
};

bool cmp(edge a, edge b){
    return a.weight > b.weight;
}

int N, M, dist[MAXN], dset[MAXN], dsize[MAXN];
vector<edge> e;
vector<pii> adjList[MAXN];

void uinit(){
	for (int i = 0; i < MAXN; i++){
		dset[i] = i, dsize[i]= 1;
	}
}

int ufind(int n){
    int root = n;

	while(root != dset[root])
		root = dset[root];

	while(root != n){
		int temp = dset[n];
		dset[n] = root;
		n = temp;
	}

	return root;
}

void umerge(int a, int b){
	int ra = ufind(a), rb = ufind(b);

	if (ra == rb) return;

	if (dsize[ra] > dsize[rb]){
		dset[rb] = ra;
		dsize[ra] += dsize[rb];
	} else {
		dset[ra] = rb;
		dsize[rb] += dsize[ra];
	}
}

void dfs(int cur, int pre){
    for (pii i : adjList[cur]){
        if (i.first != pre){
            dist[i.first] = min(dist[cur], i.second);
            dfs(i.first, cur);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0, a, b, w; i < M; i++){
        cin >> a >> b >> w;
        a--, b--;
        e.push_back(edge(a, b, w));
    }

    uinit();
    sort(e.begin(), e.end(), cmp);

    for (edge cur : e){
        if (ufind(cur.src) != ufind(cur.tar)){
            umerge(cur.src, cur.tar);
            adjList[cur.src].push_back(make_pair(cur.tar, cur.weight));
            adjList[cur.tar].push_back(make_pair(cur.src, cur.weight));
        }
    }

    dist[0] = INF;
    dfs(0, -1);

    dist[0] = 0;
    for (int i = 0; i < N; i++)
        printf("%d\n", dist[i]);
}
