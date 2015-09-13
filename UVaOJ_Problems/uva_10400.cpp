
#include <bits/stdc++.h>

using namespace std;

int T, N, target, numbers[101];
string result;

bool visited[101][70000];

bool dfs(int nextTerm, int currentResult, string signs){
    if (nextTerm == N){
        if (currentResult == target) {
            result = signs;
            return true;
        }
        return false;
    }

    if (currentResult > 32000 || currentResult < -32000) return false;
    if (visited[nextTerm][currentResult + 32001]) return false;
    visited[nextTerm][currentResult + 32001] = true;

    bool ans = false;

    if (dfs(nextTerm + 1, currentResult + numbers[nextTerm], signs + "+"))
        return true;

    if (dfs(nextTerm + 1, currentResult - numbers[nextTerm], signs + "-"))
        return true;

    if (dfs(nextTerm + 1, currentResult * numbers[nextTerm], signs + "*"))
        return true;

    if (currentResult % numbers[nextTerm] == 0)
        if (dfs(nextTerm + 1, currentResult / numbers[nextTerm], signs + "/"))
            return true;

    return false;
}

int main(){
    scanf("%d", &T);

    while(T--){
        memset(visited, 0, sizeof visited);

        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", &numbers[i]);
        scanf("%d", &target);

        result = "NO EXPRESSION";
        dfs(1, numbers[0], "");

        if (result == "NO EXPRESSION"){
            cout << result << endl;
        } else {
            cout << numbers[0];
            for (int i = 0; i < result.length(); i++){
                cout << result[i] << numbers[i + 1];
            }
            cout << "=" << target << endl;
        }
    }
}
