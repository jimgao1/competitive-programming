
#include "stdafx.h"

#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

#define MAXN 100
#define INF 1000000

using namespace std;

int matrix[MAXN][MAXN];
int dist[MAXN];
bool qContains[MAXN];

int _tmain(int argc, _TCHAR* argv[])
{
	int nodeCount, edgeCount;
	cin >> nodeCount >> edgeCount;

	for (int i = 0; i < nodeCount; i++)
		for (int j = 0; j < nodeCount; j++)
			matrix[i][j] = -1;
	
	for (int i = 0; i < edgeCount; i++){

		int nodeA, nodeB, dist;
		cin >> nodeA >> nodeB >> dist;

		matrix[nodeA][nodeB] = dist;
		matrix[nodeB][nodeA] = dist;
	}

	for (int i = 0; i < nodeCount; i++)
		dist[i] = INF;

	int startNode;
	cin >> startNode;

	queue<int> spfa;
	spfa.push(startNode);

	dist[startNode] = 0;
	qContains[startNode] = true;

	while (!spfa.empty()){
		int current = spfa.front();
		spfa.pop();

		qContains[current] = false;

		for (int i = 0; i < nodeCount; i++){
			if (matrix[current][i] != -1 && dist[i] > dist[current] + matrix[current][i]){
				dist[i] = dist[current] + matrix[current][i];

				if (!qContains[i]){
					qContains[i] = true;
					spfa.push(i);
				}
			}
		}
	}

	for (int i = 0; i < nodeCount; i++){
		cout << "dist[" << i << "] = " << dist[i] << endl;
	}

	system("pause");

	return 0;
}

