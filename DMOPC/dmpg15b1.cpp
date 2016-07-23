
#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    for (int i = 0; i < N; i++){
        string str;
        cin >> str;

        if (str.size() == 10 && (str.substr(0, 3) == "416" || str.substr(0, 3) == "647")){
            printf("(%c%c%c)-%c%c%c-%c%c%c%c\n",
            str[0], str[1], str[2], str[3], str[4], str[5], str[6], str[7], str[8], str[9]);
        } else {
            cout << "not a phone number" << endl;
        }
    }
}
