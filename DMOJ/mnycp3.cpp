#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, string>> gen, girl;
vector<string> go;

int main(){
    cin >> N;
    for (int i = 0; i < N; i++){
        string name;
        string type;
        int rating;

        cin >> name >> type >> rating;
        if (type == "general"){
            gen.push_back({rating, name});
        } else if (type == "girls"){
            girl.push_back({rating, name});
        }
    }

    sort(girl.begin(), girl.end(), greater<pair<int, string>>());

    if (girl.size() > 0){
        go.push_back(girl[0].second);
        //girl.erase(girl.begin());
    }

    for (int i = 1; i < girl.size(); i++)
        gen.push_back(girl[i]);

    sort(gen.begin(), gen.end(), greater<pair<int, string>>());

    for (int i = 0; i < min(2, (int)(gen.size())); i++){
        go.push_back(gen[i].second);
    }

    if (go.size() == 0){
        cout << "No ECOO :(" << endl;
    } else {
        sort(go.begin(), go.end());
        for (string c : go)
            cout << c << endl;
    }
}
