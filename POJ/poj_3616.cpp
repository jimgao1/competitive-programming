
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R;

struct time_period{
    int start_time, end_time, efficiency;

    time_period(int a, int b, int c){
        start_time = a, end_time = b, efficiency = c;
    }
};

bool comp(time_period a, time_period b){
    return a.start_time < b.start_time;
}

vector<time_period> p;
int dp[1100];

int main(){
    cin >> N >> M >> R;

    for (int i=0, a, b, c; i<M; i++){
        cin >> a >> b >> c;
        p.push_back(time_period(a, b + R, c));
    }

    sort(p.begin(), p.end(), comp);

    for (int i=0; i<M; i++){
        dp[i] = p[i].efficiency;

        for (int j=0; j<i; j++){
            if (p[j].end_time <= p[i].start_time)
                dp[i] = max(dp[i], dp[j] + p[i].efficiency);
        }
    }

    int tmax = 0;

    for (int i=0; i<M; i++)
        tmax = max(tmax, dp[i]);

    cout << tmax << endl;

    return 0;
}
