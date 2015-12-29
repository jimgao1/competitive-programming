
#include <bits/stdc++.h>

using namespace std;

struct edge{
    int src, tar;
    double rate;

    edge(int a, int b, double c){
        src = a, tar = b, rate = c;
    }
};

int N, M, cnt = 0;
double r[501];

unordered_map<string, int> dict;
vector<edge> e;

int main(){
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++){
        string str;
        cin >> str;

        dict[str] = cnt++;
    }

    for (int i = 0; i < M; i++){
        string sa, sb;
        double rate;
        cin >> sa >> sb >> rate;
        e.push_back(edge(dict[sa], dict[sb], rate));
    }

    r[dict["APPLES"]] = 1.0;

    for (int i = 0; i < N; i++){
        for (edge j : e){
            r[j.tar] = max(r[j.tar], r[j.src] * j.rate);
        }
    }

    double tmp = r[dict["APPLES"]];
    for (edge i : e){
        r[i.tar] = max(r[i.tar], r[i.src] * i.rate);
    }

    if (r[dict["APPLES"]] - tmp > 0.01)
        cout << "YA" << endl;
    else
        cout << "NAW" << endl;
}
