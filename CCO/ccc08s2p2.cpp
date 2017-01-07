
#include <bits/stdc++.h>

#define MAXN 200010
#define endl "\n"

using namespace std;

int N, M, Q, type[MAXN], dset[MAXN], dsize[MAXN];
bool visited[MAXN], conflict = false;
vector<pair<int, int>> adjList[MAXN], intersect;
map<string, int> dict;

void uinit(){
    for (int i = 0; i < MAXN; i++)
        dset[i] = i, dsize[i] = 1;
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

int lookup(string str){
    if (dict.find(str) == dict.end()){
        dict[str] = dict.size();
    }
    return dict[str];
}

void dfs(int cur){
    if (visited[cur]) return;
    visited[cur] = true;
    for (pair<int, int> i : adjList[cur]){
        if (i.second == 1){
            if (visited[i.first] && type[i.first] != type[cur]){
                conflict = true;
                return;
            }
            type[i.first] = type[cur];
        } else {
            if (visited[i.first] && type[i.first] != 3 - type[cur]){
                conflict = true;
                return;
            }
            type[i.first] = 3 - type[cur];
        }
        dfs(i.first);
    }
}

int main(){
    //freopen("weber.in", "r", stdin);
    //freopen("weber.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    uinit();
    cin >> M >> Q;
    for (int i = 0; i < M; i++){
        string a, b, prop;
        cin >> a >> b >> prop;
        int na = lookup(a), nb = lookup(b);
        if (prop == "parallel"){
            adjList[na].push_back({nb, 1});
            adjList[nb].push_back({na, 1});
            umerge(na, nb);
        } else if (prop == "intersect"){
            adjList[na].push_back({nb, 2});
            adjList[nb].push_back({na, 2});
            intersect.push_back({na, nb});
        }
    }
    N = dict.size();

    for (pair<int, int> i : intersect){
        if (ufind(i.first) == ufind(i.second)){
            cout << "Waterloo" << endl;
            return 0;
        }
    }

    for (pair<int, int> i : intersect){
        umerge(i.first, i.second);
    }

    for (int i = 0; i < N; i++){
        if (visited[i]) continue;
        type[i] = 1;
        dfs(i);
    }

    if (conflict) {
        cout << "Waterloo" << endl;
        return 0;
    }

    for (int i = 0; i < Q; i++){
        string sa, sb;
        cin >> sa >> sb;
        if (dict.find(sa) == dict.end() || dict.find(sb) == dict.end()){
            cout << "unknown" << endl;
            continue;
        }
        int na = lookup(sa), nb = lookup(sb);

        if (ufind(na) == ufind(nb)){
            if (type[na] == type[nb])
                cout << "parallel" << endl;
            else
                cout << "intersect" << endl;
        } else {
            cout << "unknown" << endl;
        }
    }
}

