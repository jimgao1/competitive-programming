/*
    Given an integer x, and a set of numbers.

    Asking whether it is possible that a subset
        of the numbers can sum up to x
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> numbers, subA, subB;
vector<int> posA, posB;
int N, x;

void gen_numbers(vector<int> num, int index, int sum, bool a){
    if (index == num.size()){
        if (a)
            posA.push_back(sum);
        else
            posB.push_back(sum);
        return;
    }

    gen_numbers(num, index + 1, sum + num[index], a);
    gen_numbers(num, index + 1, sum, a);

    return;
}

int main(){
    cin >> N >> x;

    for (int i=0, cur; i<N; i++){
        cin >> cur;
        numbers.push_back(cur);
    }

    int mid = N / 2;

    for (int i=0; i<mid; i++) subA.push_back(numbers[i]);
    for (int i=mid; i<N; i++) subB.push_back(numbers[i]);

    gen_numbers(subA, 0, 0, true);
    gen_numbers(subB, 0, 0, false);

    for (int a : posA){
        for (int b : posB){
            if (a + b == x){
                cout << "possible" << endl;
                return;
            }
        }
    }

    cout << "impossible" << endl;

    return 0;
}
