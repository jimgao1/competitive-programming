
#include <bits/stdc++.h>

using namespace std;

struct guess{
    string number;
    int correct, wrong_place;

    guess(string a, int b, int c){
        number = a, correct = b, wrong_place = c;
    }
};

vector<guess> vg;
vector<string> possible;

int occ[10];

bool verify_guess(string current, string correct, int a, int b){
    int ca = 0, cb = 0;

    for (int i = 0; i < 4; i++){
        if (current[i] == correct[i]) ca++;
    }

    memset(occ, 0, sizeof occ);
    for (int i = 0; i < 4; i++) occ[current[i] - '0'] ++;
    for (int i = 0; i < 4; i++) {
        if (occ[correct[i] - '0'] != 0){
            cb++;
            occ[correct[i] - '0'] -= 1;
        }
    }

    cb -= ca;

    return (ca == a && cb == b);
}

int N, G;

int main(){
    cin >> N;

    while(N--){
        cin >> G;
        vg.clear();
        possible.clear();

        for (int i = 0; i < G; i++){
            string cg, strguess;
            cin >> cg >> strguess;

            int slashIndex = -1;
            for (int j = 0; j < strguess.length(); j++){
                if (strguess[j] == '/'){
                    slashIndex = j;
                    break;
                }
            }

            int firstNumber = atoi(strguess.substr(0, slashIndex).c_str());
            int secondNumber = atoi(strguess.substr(slashIndex + 1).c_str());

            //printf("first = %d, second = %d\n", firstNumber, secondNumber);

            vg.push_back(guess(cg, firstNumber, secondNumber));
        }

        for (int i = 0; i < 10000; i++){
            //printf("currently testing %d\n", i);

            string n = to_string(i);
            while(n.length() < 4) n = "0" + n;

            bool pass = true;

            for (int j = 0; j < vg.size(); j++){
                bool result = verify_guess(vg[j].number, n, vg[j].correct, vg[j].wrong_place);

                //printf("\ttest case %d %s. \n", j, (result ? "true" : "false"));
                if (!result) pass = false;
            }

            if (pass) {
                possible.push_back(n);
                //printf("passed: %d\n", i);
            }
        }

        if (possible.size() == 0){
            printf("impossible\n");
        } else if (possible.size() > 1){
            printf("indeterminate\n");
        } else {
            printf("%s\n", possible[0].c_str());
        }
    }
}

