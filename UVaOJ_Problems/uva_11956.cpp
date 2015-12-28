
#include <bits/stdc++.h>

using namespace std;

int T, mem[100];

int main(){
    freopen("input.txt", "r", stdin);

    cin >> T;
    for (int c = 1; c <= T; c++){
        string line;
        cin >> line;

        memset(mem, 0, sizeof mem);
        int point = 0;

        for (char c : line){
            if (c == '<'){
                point = (point + 99) % 100;
            } else if (c == '>'){
                point = (point + 1) % 100;
            } else if (c == '+'){
                mem[point] = (mem[point] + 1) % 256;
            } else if (c == '-'){
                mem[point] = (mem[point] + 255) % 256;
            } else if (c == '.'){
                //printf("%X ", mem[point]);
            }
        }

        printf("Case %d: ", c);
        for (int i = 0; i < 100; i++){
            mem[i] = mem[i] % 256;

            if (i != 0) printf(" ");
            if (mem[i] < 16){
                printf("0%X", mem[i]);
            } else {
                printf("%X", mem[i]);
            }
        }
        printf("\n");
    }
}
