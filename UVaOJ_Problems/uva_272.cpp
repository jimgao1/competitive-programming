#include <bits/stdc++.h>

using namespace std;

int main(){

    int a = 0;

	while(!cin.eof()){
        if (a > 0) cout << endl;

		string str;
		getline(cin, str);

		for (char c : str){
			if (c == '"')
				cout << ((a++) % 2 == 0 ? "``" : "''");
			else
				cout << c;
		}

	}
}
