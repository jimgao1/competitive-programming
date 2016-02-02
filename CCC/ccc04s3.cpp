
#include <bits/stdc++.h>

using namespace std;

string grid[11][11];
bool defined[11][11];
int sheet[11][11];

pair<int, int> convert(string str){
    return {str[0] - 'A', str[1] - '0' - 1};
}

int evaluate(string str){
    int sum = 0;
    for (int i = 0; i < str.size(); i += 3){
        auto c = convert(str.substr(i, 2));

        if (!defined[c.first][c.second]) return -1;
        sum += sheet[c.first][c.second];
    }
    return sum;
}

int main(){
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 9; j++){
            cin >> grid[i][j];
        }
    }

    while(true){
        int changed = 0;

        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 9; j++){
                if (defined[i][j]) continue;

                if (grid[i][j][0] >= '0' && grid[i][j][0] <= '9'){
                    sheet[i][j] = atoi(grid[i][j].c_str());
                } else {
                    sheet[i][j] = evaluate(grid[i][j]);
                }

                if (sheet[i][j] != -1){
                    defined[i][j] = true;
                    changed ++;
                }
            }
        }

        if (changed == 0) break;

    }


    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 9; j++){
            if (sheet[i][j] == -1)
                cout << "* ";
            else
                cout << sheet[i][j] << " ";
        }
        cout << endl;
    }
}
