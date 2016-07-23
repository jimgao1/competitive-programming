
#include <bits/stdc++.h>

using namespace std;

int W, H, cnt = 0;

int main(){
    cin >> W >> H;
    string line;

    getline(cin, line);

    while(H--){
        getline(cin, line);

        for (int i = 0; i < line.size(); i++) {
            if (line[i] == 'o'){
                line[i] = ' ';
                cnt++;
            } else if (line[i] == '*'){
                line[i] = ' ';
            }
        }

        cout << line << endl;
    }

    for (int i = 0; i < cnt; i++) cout << "o";
    cout << endl;
}
