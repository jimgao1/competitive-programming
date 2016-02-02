
#include <bits/stdc++.h>

using namespace std;

bool monkey(string str){
    if (str == "") return false;
    if (str == "A") return true;

    if (str[0] == 'B' && str[str.size() - 1] == 'S')
        if (monkey(str.substr(1, str.length() - 2)))
            return true;

    for (int i = 0; i < str.size(); i++){
        if (str[i] == 'N'){
            if (i == 0) continue;

            if (monkey(str.substr(0, i)) && monkey(str.substr(i + 1)))
                return true;
        }
    }

    return false;
}

int main(){
    while(true){
        string str;
        cin >> str;

        if (str == "X") break;

        if (monkey(str))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
