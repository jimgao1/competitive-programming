
#include <bits/stdc++.h>

using namespace std;

struct comp{
    string name;
    int ram, cpu, disk;

    comp(string a, int b, int c, int d){
        name = a, ram = b, cpu = c, disk = d;
    }

    int value(){
        return 2 * ram + 3 * cpu + disk;
    }
};

bool cmp(comp a, comp b){
    if (a.value() != b.value())
        return a.value() > b.value();
    return a.name < b.name;
}

int N;
vector<comp> cl;

int main(){
    cin >> N;

    if (N == 0) return 0;

    while(N--){
        string a;
        int b, c, d;
        cin >> a >> b >> c >> d;
        cl.push_back(comp(a, b, c, d));
    }

    sort(cl.begin(), cl.end(), cmp);

    if (cl.size() == 1){
        cout << cl[0].name << endl;
    } else {
        cout << cl[0].name << endl;
        cout << cl[1].name << endl;
    }
}
