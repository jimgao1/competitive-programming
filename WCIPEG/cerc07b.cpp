
#include <bits/stdc++.h>

using namespace std;

int R, C, init[16], board[16];

bool getBit(int* b, int r, int c){ return b[r] & (1 << c); }
void setBit(int* b, int r, int c){ b[r] |= (1 << c); }
void toggleBit(int* b, int r, int c) { b[r] ^= (1 << c); }

void tap(int* b, int r, int c){
    toggleBit(b, r, c);
    if (r > 0) toggleBit(b, r - 1, c);
    if (r < R - 1) toggleBit(b, r + 1, c);
    if (c > 0) toggleBit(b, r, c - 1);
    if (c < C - 1) toggleBit(b, r, c + 1);
}

int main(){
    cin >> R >> C;
    for (int i = 0; i < R; i++){
        string line;
        cin >> line;
        for (int j = 0; j < C; j++){
            if (line[j] == 'X'){
                setBit(init, i, j);
            }
        }
    }

    int ans = 1e9;

    for (int i = 0; i < (1 << C); i++){
        int cnt = 0;

        //Move the board over
        for (int j = 0; j < R; j++){
            board[j] = init[j];
        }
        //Tap on things
        for (int j = 0; j < C; j++){
            if (i & (1 << j)){
                cnt ++;
                tap(board, 0, j);
            }
        }
        //More tapping
        for (int j = 1; j < R; j++){
            for (int k = 0; k < C; k++){
                if (getBit(board, j - 1, k)){
                    tap(board, j, k);
                    cnt ++;
                }
            }
        }

        if (board[R - 1] == 0){
            ans = min(ans, cnt);
        }
    }

    if (ans == 1e9){
        printf("Damaged billboard.\n");
    } else {
        printf("You have to tap %d tiles.\n", ans);
    }
}
