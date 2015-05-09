/*
ID: jim_yub1
LANG: C++11
TASK: ttwo
*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct state{
	int farmerX, farmerY;
	int cowX, cowY;
	int dirFarmer, dirCow;
	int time;
};

/*
	North: x, y - 1
	East:  x + 1, y
	South: x, y + 1
	West:  x - 1, y
*/

int dX[] = { 0, 1, 0, -1 };
int dY[] = { -1, 0, 1, 0 };

bool visited[1100000] = { false };
char map[10][10];

unsigned long long int c_hash(state s){
	return s.farmerX + 10 * s.farmerY + 100 * s.cowX + 1000 * s.cowY + 10000 * s.dirFarmer + 100000 * s.dirCow;
}

int main(){
    freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w", stdout);

	state initial;
	initial.dirFarmer = 0;
	initial.dirCow = 0;
	initial.time = 0;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++){
			cin >> map[j][i];
			if (map[j][i] == 'F'){
				initial.farmerX = j;
				initial.farmerY = i;
			}
			else if (map[j][i] == 'C'){
				initial.cowX = j;
				initial.cowY = i;
			}
		}

	//cout << initial.cowX << "\t" << initial.cowY << "\t" << initial.farmerX << "\t" << initial.farmerY << endl;

	bool completed = false;

	queue<state> search;
	search.push(initial);

	while (!search.empty()){
		state current = search.front();
		search.pop();

		/*
			Check Base Case
		*/

		if (current.farmerX == current.cowX && current.farmerY == current.cowY){
			completed = true;
			cout << current.time << endl;
			break;
		}

		/*
			Check Visited
		*/

		//cout << "hash = " << c_hash(current) << endl;

		if (visited[c_hash(current)]) {
			//cout << "current case already visited " << endl;
			continue;
		}
		visited[c_hash(current)] = true;

		/*
			Check out of bounds
		*/
		int newFarmerX = current.farmerX + dX[current.dirFarmer], newFarmerY = current.farmerY + dY[current.dirFarmer];
		int newCowX = current.cowX + dX[current.dirCow], newCowY = current.cowY + dY[current.dirCow];

		bool invalidFarmer = false, invalidCow = false;

		if (newFarmerX < 0 || newFarmerX >= 10 || newFarmerY < 0 || newFarmerY >= 10)
			invalidFarmer = true;
		else if (map[newFarmerX][newFarmerY] == '*')
			invalidFarmer = true;

		if (newCowX < 0 || newCowX >= 10 || newCowY < 0 || newCowY >= 10)
			invalidCow = true;
		else if (map[newCowX][newCowY] == '*')
			invalidCow = true;

		/*
			Update new state
		*/

		current.time += 1;

		if (invalidFarmer){
			current.dirFarmer = (current.dirFarmer + 1) % 4;
		}
		else{
			current.farmerX = newFarmerX;
			current.farmerY = newFarmerY;
		}

		if (invalidCow){
			current.dirCow = (current.dirCow + 1) % 4;
		}
		else {
			current.cowX = newCowX;
			current.cowY = newCowY;
		}

		search.push(current);

	}

	if (!completed)
		cout << "0" << endl;

	//system("pause");
	return 0;
}
