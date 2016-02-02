/*
ID: jim_yub1
LANG: C++11
TASK: milk2
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define USACO
#define FILEIN "milk2.in"
#define FILEOUT "milk2.out"

struct TimePeriod{
	int startTime;
	int endTime;
};


int main(){

	#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
	#endif

	int mCount;
	cin >> mCount;

	int earliest = 1000000;
	int latest = -1;

	vector<TimePeriod> periods;

	for (int i = 0; i < mCount; i++){
		int sTime, eTime;
		cin >> sTime >> eTime;

		TimePeriod t;
		t.startTime = sTime;
		t.endTime = eTime;

		earliest = min(earliest, sTime);
		latest = max(latest, eTime);

		periods.push_back(t);
	}

	/*
		Maximum Continuous Milking Time
	*/

	int maxTime = 0;
	int timeCounter = 0;
	bool curMilk = false;

	int maxIdleTime = 0;
	int idleCounter = 0;
	bool curIdle = false;

	for (int i = earliest; i <= latest; i++){

		/*
			Milking Counters
		*/
		bool milking = false;

		for (int j = 0; j < periods.size(); j++)
			if (i >= periods[j].startTime && i < periods[j].endTime + 1){
				milking = true;
				break;
			}

		if (curMilk && milking){
			timeCounter += 1;
			maxTime = max(maxTime, timeCounter);
		}
		else if (!curMilk){
			timeCounter = 1;
			curMilk = true;
		}
		else if (!milking){
			curMilk = false;
			maxTime = max(maxTime, timeCounter);
			timeCounter = 0;
		}



		/*
			Idle Counters
		*/

		bool idle = !milking;

		if (curIdle && idle){
			idleCounter += 1;
			maxIdleTime = max(maxIdleTime, idleCounter);
		}
		else if (idle){
			idleCounter = 1;
			curIdle = true;
		}
		else if (!idle){
			curIdle = false;
			maxIdleTime = max(maxIdleTime, idleCounter);
			idleCounter = 0;
		}

		//cout << i << " " << milking << " " << timeCounter << " " << idleCounter << endl;
	}

	cout << maxTime - 1 << " " << maxIdleTime << endl;

};
