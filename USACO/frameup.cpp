/*
ID: jim_yub1
LANG: C++11
TASK: frameup
*/

#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

struct shape{
    int min_x, min_y, max_x, max_y;

    void init(){
        min_x = INF, min_y = INF;
        max_x = -1, max_y = -1;
    }
};

shape rect[30];

int W, H, pos[30], ncnt = 0;
char grid[31][31];
bool matrix[30][30], used[30];

unordered_map<char, int> dict;
vector<char> letters;
vector<string> solutions;
vector<int> todo;

inline bool getBit(int n, int bit){ return n & (1 << bit); }
inline int setBit(int n, int bit) { return n | (1 << bit); }

string char_to_string(char c){
    string s = " ";
    s[0] = c;

    return s;
}

void dfs(int current, int visited, string result){
    if (result.length() == letters.size()){
        reverse(result.begin(), result.end());
        solutions.push_back(result);
        return;
    }

    for (int i = 0; i < letters.size(); i++){
        bool flag = !getBit(visited, i);

        for (int j = 0; j < letters.size(); j++){
            if (!getBit(visited, j) && matrix[j][i]) {
                flag = false;
                break;
            }
        }

        if (flag)
            dfs(i, setBit(visited, i), result + char_to_string(letters[i]));
    }
}

int main(){
    freopen("frameup.in", "r", stdin);
    freopen("frameup.out", "w", stdout);

    for (int i = 0; i < 30; i++) rect[i].init();

    cin >> H >> W;

    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            cin >> grid[j][i];

            if (!used[grid[j][i] - 'A'] && grid[j][i] != '.'){
                letters.push_back(grid[j][i]);
                used[grid[j][i] - 'A'] = true;
            }
        }
    }

    sort(letters.begin(), letters.end());

    for (int i = 0; i < letters.size(); i++){
        dict[letters[i]] = i;
    }

    for (int i = 0; i < W; i++){
        for (int j = 0; j < H; j++){
            if (grid[i][j] != '.'){
                int id = dict[grid[i][j]];

                rect[id].max_x = max(rect[id].max_x, i);
                rect[id].min_x = min(rect[id].min_x, i);
                rect[id].max_y = max(rect[id].max_y, j);
                rect[id].min_y = min(rect[id].min_y, j);
            }
        }
    }

    for (int i = 0; i < letters.size(); i++){

        for (int j = rect[i].min_x; j <= rect[i].max_x; j++){
            if (grid[j][rect[i].min_y] != letters[i]){
                matrix[dict[grid[j][rect[i].min_y]]][i] = true;
            }

            if (grid[j][rect[i].max_y] != letters[i]){
                matrix[dict[grid[j][rect[i].max_y]]][i] = true;
            }
        }

        for (int j = rect[i].min_y; j <= rect[i].max_y; j++){
            if (grid[rect[i].min_x][j] != letters[i]){
                matrix[dict[grid[rect[i].min_x][j]]][i] = true;
            }

            if (grid[rect[i].max_x][j] != letters[i]){
                matrix[dict[grid[rect[i].max_x][j]]][i] = true;
            }
        }
    }

    for (int i = 0; i < letters.size(); i++){
        bool flag = true;

        for (int j = 0; j < letters.size(); j++)
            if (matrix[j][i] && i != j) flag = false;

        if (flag) todo.push_back(i);
    }


    for (int i = 0; i < todo.size(); i++){
        dfs(todo[i], setBit(0, todo[i]), char_to_string(letters[todo[i]]));
    }

    sort(solutions.begin(), solutions.end());

    for (string str : solutions) cout << str << endl;
}
