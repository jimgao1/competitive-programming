
#include <iostream>

using namespace std;

int cost, students;
double y1, y2, y3, y4;

void doit(){
    cin >> cost >> y1 >> y2 >> y3 >> y4 >> students;

    double total = 0;
    total += y1 * 12 * students;
    total += y2 * 10 * students;
    total += y3 * 7 * students;
    total += y4 * 5 * students;

    if (total * 0.5 >= cost){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main(){
    int T = 10;
    while(T--) doit();
}

