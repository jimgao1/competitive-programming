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
	int start;
	int end;
};

int main(){

	#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
	#endif

	int periodCount;
	cin >> periodCount;

	int minTime = 1000000;
	int maxTime = -1;

	vector<TimePeriod> periods;

	for (int i = 0; i < periodCount; i++){
		int sTime, eTime;
		cin >> sTime >> eTime;

		minTime = min(minTime, sTime);
		maxTime = max(maxTime, eTime);

		TimePeriod s;
		s.start = sTime;
		s.end = eTime;

		periods.push_back(s);
	}

	bool prevMilking = false;
	bool prevIdling = false;

	int milkingCount = 0;
	int idlingCount = 0;

	int maxMilking = 0;
	int maxIdling = 0;

	/*
		Iterating through time periods (i) to (i + 1)
	*/
	for (int i = minTime; i < maxTime; i++){
		bool currentMilking = false;

		for (int j = 0; j < periodCount; j++){
			if (periods[j].start <= i && periods[j].end >= i + 1){
				currentMilking = true;
				break;
			}
		}

		if (currentMilking){
			maxIdling = max(idlingCount, maxIdling);
			idlingCount = 0;

			if (prevMilking){
				milkingCount += 1;
				maxMilking = max(maxMilking, milkingCount);
			}
			else {
				milkingCount = 1;
				prevMilking = true;
				maxMilking = max(maxMilking, milkingCount);
			}
		}
		else {
			maxMilking = max(milkingCount, maxMilking);
			milkingCount = 0;

			if (prevIdling){
				idlingCount += 1;
				maxIdling = max(maxIdling, idlingCount);
			}
			else {
				idlingCount = 1;
				prevIdling = true;
				maxIdling = max(maxIdling, idlingCount);
			}
		}

	}

	cout << maxMilking << " " << maxIdling << endl;

};
