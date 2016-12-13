
#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> ans;

bool palindrome(int num, int base){
    vector<int> digits;
    while(num > 0){
        digits.push_back(num % base);
        num /= base;
    }
    for (int i = 0; i < digits.size() / 2; i++){
        if (digits[i] != digits[digits.size() - i - 1])
            return false;
    }
    return true;
}

int main(){
    cin >> N;
    for (int i = 2; i <= sqrt(N); i++){
        if (palindrome(N, i)) ans.push_back(i);
    }

    for (int i = 1; i <= sqrt(N); i++){
        if ((N - i) % i == 0 && N % ((N - i) / i) != 0){
            ans.push_back((N - i) / i);
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for (int i : ans) cout << i << endl;
}
