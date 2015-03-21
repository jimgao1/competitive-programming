
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

struct line{
	int x1, y1;
	int x2, y2;
};

int diff(int aX, int aY, int bX, int bY, int cX, int cY){
	return (bX - aX) * (cY - aY) - (bY - aY) * (cX - aX);
}

int main(){
	
	while (true){
		int partCount, toyCount, rectX1, rectY1, rectX2, rectY2;

		cin >> partCount;
		if (partCount == 0) break;

		cin >> toyCount >> rectX1 >> rectY1 >> rectX2 >> rectY2;

		int *count = new int[partCount + 2];
		for (int i = 0; i < partCount + 1; i++)
			count[i] = 0;

		vector<line> lines;

		line left;
		left.x1 = rectX1;
		left.y1 = rectY1;
		left.x2 = rectX1;
		left.y2 = rectY2;

		lines.push_back(left);

		for (int i = 0; i < partCount; i++){
			int pointX1, pointX2;
			cin >> pointX1 >> pointX2;

			line newLine;
			newLine.x1 = pointX1;
			newLine.y1 = rectY1;
			newLine.x2 = pointX2;
			newLine.y2 = rectY2;

			lines.push_back(newLine);
		}

		line right;
		right.x1 = rectX2;
		right.y1 = rectY1;
		right.x2 = rectX2;
		right.y2 = rectY2;

		lines.push_back(right);


		/*
			Begin Inquiry
		*/

		for (int i = 0; i < toyCount; i++){
			int tX1, tX2;
			cin >> tX1 >> tX2;

			//cout << "node #" << i << endl;

			for (int j = 0; j < lines.size() - 1; j++){

				int d1 = diff(lines[j].x1, lines[j].y1, lines[j].x2, lines[j].y2, tX1, tX2);
				int d2 = diff(lines[j + 1].x1, lines[j + 1].y1, lines[j + 1].x2, lines[j + 1].y2, tX1, tX2);

				if (d1 > 0 && d2 < 0){
					count[j] += 1;
					goto hell;
				}
			}

		hell:
			continue;

		}

		for (int i = 0; i < partCount + 1; i++){
			cout << i << ": " << count[i] << endl;
		}

		cout << endl;
	}


}
