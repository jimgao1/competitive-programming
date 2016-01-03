
#include <bits/stdc++.h>

using namespace std;

int T;

int main(){
    cin >> T;
    while(T--){
        string str;
        cin >> str;

        bool flag = false;

        for (int i = 0; i < str.size(); i++){
            for (int j = i + 1; j < str.size(); j++){
                for (int k = j + 1; k < str.size() - 1; k++){
                    string s1 = str.substr(0, i + 1);
                    string s2 = str.substr(i + 1, j - i);
                    string s3 = str.substr(j + 1, k - j);
                    string s4 = str.substr(k + 1);

                    if (s1.size() == 0 || s2.size() == 0 || s3.size() == 0 && s4.size() == 0)
                        continue;

                    if (s1 != s2 && s1 != s3 && s1 != s4 &&
                        s2 != s3 && s2 != s4 && s3 != s4){
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }

        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

}
