/*
ID: jim_yub1
LANG: C++11
TASK: friday
*/


#include <iostream>


using namespace std;

#define USACO
#define FILEIN "friday.in"
#define FILEOUT "friday.out"

#define MAXN 10

int main(){

	#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
	#endif

	int leapYear[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int nonLeapYear[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int currentYear, currentMonth, currentDay;

	/*
		Current Weekday:
			Saturday		0
			Sunday			1
			Monday			2
			Tuesday			3
			Wednesday		4
			Thursday		5
			Friday			6
	*/
	int currentWeekday = 2;

	int thirteenCount[7] = { 0, 0, 0, 0, 0, 0, 0 };

	int yearCount;
	cin >> yearCount;

	for (int currentYear = 1900; currentYear < (1900 + yearCount); currentYear++){
		bool leap;

		if (currentYear % 4 != 0)
			leap = false;
		else if (currentYear % 100 != 0)
			leap = true;
		else if (currentYear % 400 != 0)
			leap = false;
		else
			leap = true;

		//cout << currentYear << "\t" << leap << endl;

		for (int currentMonth = 0; currentMonth < 12; currentMonth++){
			int days;
			if (leap)
				days = leapYear[currentMonth];
			else
				days = nonLeapYear[currentMonth];

			for (int currentDay = 0; currentDay < days; currentDay++){

				//cout << currentYear << "\t" << currentMonth << "\t" << currentDay << "\t" << currentWeekday << endl;

				if (currentDay == 12)
					thirteenCount[currentWeekday] += 1;

				currentWeekday += 1;

				if (currentWeekday == 7) currentWeekday = 0;
			}
		}

	}

	for (int i = 0; i < 7; i++)
		if (i != 6)
			cout << thirteenCount[i] << " ";
		else
			cout << thirteenCount[6] << endl;


}
