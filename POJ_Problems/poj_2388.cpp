
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> numbers;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0, x; i < N; i++){
        cin >> x;
        numbers.push_back(x);
    }

    sort(numbers.begin(), numbers.end());

    if (N % 2 == 1){
        cout << numbers[N / 2] << "\n";
    } else {
        cout << ((double)(numbers[N / 2 - 1]) + numbers[N / 2]) / 2.0 << "\n";
    }
}
