
#include <bits/stdc++.h>

using namespace std;

int S, N, C;
map<string, int> spam, notspam, msg;

double calc(map<string, int> a, map<string, int> b){
    double num = 0, d1 = 0, d2 = 0;
    for (map<string, int>::iterator i = a.begin(); i != a.end(); i++){
        num += i->second * b[i->first];
    }
    for (map<string, int>::iterator i = a.begin(); i != a.end(); i++){
        d1 += pow(i->second, 2);
    }
    for (map<string, int>::iterator i = b.begin(); i != b.end(); i++){
        d2 += pow(i->second, 2);
    }
    return num / sqrt(d1 * d2);
}

int main(){
    //freopen("spam.in", "r", stdin);

    cin >> S >> N >> C;
    for (int i = 0; i < S; i++){
        string line;
        while(true){
            getline(cin, line);
            if (line.size() < 3) continue;
            if (line == "ENDMESSAGE") break;
            for (int i = 0; i < line.size() - 2; i++){
                spam[line.substr(i, 3)] ++;
            }
        }
    }

    for (int i = 0; i < N; i++){
        string line;
        while(true){
            getline(cin, line);
            if (line.size() < 3) continue;
            if (line == "ENDMESSAGE") break;
            for (int i = 0; i < line.size() - 2; i++){
                notspam[line.substr(i, 3)] ++;
            }
        }
    }

    for (int i = 0; i < C; i++){
        msg.clear();
        string line;
        while(true){
            getline(cin, line);
            if (line.size() < 3) continue;
            if (line == "ENDMESSAGE") break;
            for (int i = 0; i < line.size() - 2; i++){
                msg[line.substr(i, 3)] ++;
            }
        }

        double r1 = calc(msg, spam), r2 = calc(msg, notspam);
        printf("%.5f %.5f\n", r1, r2);
        cout << (r1 <= r2 ? "non-spam" : "spam") << endl;
    }
    
}

