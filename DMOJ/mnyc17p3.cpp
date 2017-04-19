
#include <bits/stdc++.h>

#define MAXN 1000001
#define ull unsigned long long
#define SEED 29

using namespace std;

string a, b;
ull h1 = 0, h2 = 0, p[MAXN];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b;

    p[0] = 1;
    for (int i = 1; i < min(a.size(), b.size()); i++){
        p[i] = p[i - 1] * SEED;
    }

    int ans = 0;
    for (int i = 0; i < min(a.size(), b.size()); i++){
        h1 = h1 + p[i] * (a[a.size() - i - 1] - 'A');
        h2 = h2 * SEED + (b[i] - 'A');

        if (h1 == h2){
            ans = i + 1;
        }
    }

    printf("%s", a.c_str());
    for (int i = ans; i < b.size(); i++){
        printf("%c", b[i]);
    }
    printf("\n");
}

