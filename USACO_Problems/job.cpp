/*
 ID: jim.yub1
 LANG: C++11
 TASK: job
 */
#include <bits/stdc++.h>


using namespace std;

int main()
{
    int atime = 0;
    
    freopen("job.in", "r", stdin);
	freopen("job.out", "w", stdout);
	
    int N, M1, M2;
    cin >> N >> M1 >> M2;
    
    vector<int> M1_time, M2_time;
    for (int i = 0; i < M1; i++) {
        int tmp;
        cin >> tmp;
        M1_time.push_back(tmp);
    }
    for (int i = 0; i < M2; i++) {
        int tmp;
        cin >> tmp;
        M2_time.push_back(tmp);
    }
    
    //get atime
    vector<int> M1finish (M1, 0), taskA (N, 0);
    for (int j = 0; j < N; j++) {
        int minfinish = INT_MAX, index = -1;
        for (int i = 0; i < M1; i++) {
            if (M1finish[i] + M1_time[i] < minfinish)
            {
                minfinish = M1finish[i] + M1_time[i];
                index = i;
            }
        }
        M1finish[index] += M1_time[index];
        atime = M1finish[index];
        taskA[j] = minfinish;
    }
    
    vector<int> M2finish (M2, 0), taskB (N, 0);
    for (int j = N-1; j >=0; j--) {
        int minfinish = INT_MAX, index = -1;
        for (int i = 0; i < M2; i++) {
            if (M2finish[i] + M2_time[i] < minfinish)
            {
                minfinish = M2finish[i] + M2_time[i];
                index = i;
            }
        }
        M2finish[index] += M2_time[index];
        taskB[j] = minfinish;
    }
    
    int total = 0;
    for (int i = 0; i < N; i++)     {         if (taskA[i] + taskB[i] > total)
        {
            total = taskA[i] + taskB[i];
        }
    }
    
	cout << atime << " " << total << endl;
    return 0;
}
