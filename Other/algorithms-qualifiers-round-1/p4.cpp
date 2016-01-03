
#include <bits/stdc++.h>

using namespace std;

int T, N, M, p[100001], q[100001], idxp[100001], idxq[100001];
int dset[100001];

void build(){
    for (int i = 0; i < 100001; i++)
        dset[i] = i;
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
	dset[ra] = rb;
}

int main(){
    scanf("%d", &T);
    while(T--){
        memset(p, 0, sizeof p);
        memset(q, 0, sizeof q);
        memset(idxp, 0, sizeof idxp);
        memset(idxq, 0, sizeof idxq);
        build();

        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; i++) {
            scanf("%d", &p[i]);
            idxp[p[i]] = i;
        }
        for (int i = 0; i < N; i++) {
            scanf("%d", &q[i]);
            idxq[q[i]] = i;
        }

        for (int i = 0, a, b; i < M; i++){
            scanf("%d%d", &a, &b);
            umerge(a - 1, b - 1);
        }
        bool flag = true;

        for (int i = 0; i < N; i++){
            if (p[i] != q[i]){
                if (ufind(idxq[p[i]]) != ufind(i)){
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
