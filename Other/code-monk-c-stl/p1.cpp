
#include <bits/stdc++.h>

using namespace std;

set<long long> contains;
int T, M, N;

int main(){
    scanf("%d", &T);
    contains.clear();

    while(T-- != 0){
        scanf("%d %d", &N, &M);
        contains.clear();

        for (int i = 0; i < N; i++){
            long long x;
            scanf("%lld", &x);
            contains.insert(x);
        }

        for (int i = 0; i < M; i++){
            long long x;
            scanf("%lld", &x);
            if (contains.find(x) != contains.end())
                printf("YES\n");
            else {
                printf("NO\n");
            }
            contains.insert(x);
        }
    }

    return 0;
}
