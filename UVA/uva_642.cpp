
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

/*
        Problem URL: http://uva.onlinejudge.org/external/6/642.pdf
*/

string sort_string(string s){

    #ifdef DEBUG
        cout << "Original String: " << s << endl;
        cout << "String Length: " << s.length() << endl;
    #endif

    string result = s;
    sort(result.begin(), result.end());

    #ifdef DEBUG
        cout << "Sorted String: " << result << endl;
    #endif

    return result;
}

int main(void){

    #ifdef LOCAL
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
    #endif

    vector<string> dictionary;

    while(true){
        string w;
        cin >> w;

        if (w != "XXXXXX")
            dictionary.push_back(w);
        else
            break;
    }

    while(true){
        string inq;
        cin >> inq;

        if (inq == "XXXXXX") break;

        sort(inq.begin(), inq.end());

        vector<string> results;

        for (int i=0; i<dictionary.size(); i++){
            string temp = dictionary[i];
            sort(temp.begin(), temp.end());

            if (temp == inq)
                results.push_back(dictionary[i]);
        }

        sort(results.begin(), results.end());

        if(results.size() != 0){
            for (int i=0; i<results.size(); i++)
                cout << results[i] << endl;
        } else {
            cout << "NOT A VALID WORD" << endl;
        }

        cout << "******" << endl;
    }
}
