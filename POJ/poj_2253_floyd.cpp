
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <queue>

#define INF 0x3f3f3f3f

using namespace std;

struct point{
	int x, y;

	point(int a, int b){
		x = a, y = b;
	}

	bool equals(point a){
		return x == a.x && y == a.y;
	}

	double dist(point a){
		return sqrt(pow((double)(x - a.x), 2) + 
			pow((double)(y - a.y), 2));
	}
};

int nodeCount;
bool visited[201];
double dist[201], matrix[201][201], maxDistance;
vector<point> p;
queue<int> dijkstra;

void init(){
	p.clear();
	while (!dijkstra.empty()) dijkstra.pop();
	maxDistance = -1;

	for (int i = 0; i < nodeCount; i++){
		visited[i] = false;
		dist[i] = INF;
	}
}

double dmax(double a, double b){
	return (a > b ? a : b);
}

double dmin(double a, double b){
	return (a < b ? a : b);
}

int main(){
	int kCount = 1;

	while (true){
		cin >> nodeCount;
		if (nodeCount == 0) break;

		init();

		for (int i = 0, x, y; i < nodeCount; i++){
			cin >> x >> y;
			p.push_back(point(x, y));
		}

		for (int i = 0; i < nodeCount; i++)
			for (int j = 0; j < nodeCount; j++)
				matrix[i][j] = p[i].dist(p[j]);

		for (int k = 0; k < nodeCount; k++)
			for (int i = 0; i < nodeCount; i++)
				for (int j = 0; j < nodeCount; j++)
					matrix[i][j] = dmin(matrix[i][j], dmax(matrix[i][k], matrix[k][j]));

		cout << "Scenario #" << kCount << endl;
		cout << "Frog Distance = " << fixed << setprecision(3) << matrix[0][1] << endl;
		cout << endl;

		kCount++;

	}

	system("pause");
	return 0;

}
