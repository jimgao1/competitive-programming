
#include <bits/stdc++.h>

using namespace std;

struct point{
    int x, y;
    point(){}
    point(int a, int b) { x = a, y = b; }
};

int N, cnt = 0;

point src, tar;
vector<vector<point>> shapes;

bool onSegment(point p, point q, point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}

int orientation(point p, point q, point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear

    return (val > 0)? 1: 2; // clock or counterclock wise
}

bool doIntersect(point p1, point q1, point p2, point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4)
        return true;

    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

int main(){
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
	src.x = a, src.y = b;
	tar.x = c, tar.y = d;

    scanf("%d", &N);

    for (int i = 0, x; i < N; i++){
        scanf("%d", &x);

        vector<point> p;

        for (int j = 0; j < x; j++){
            scanf("%d%d", &a, &b);
            p.push_back(point(a, b));
        }

        shapes.push_back(p);
    }

	for (int i = 0; i < shapes.size(); i++){
		bool c = false;

        for (int j = 0; j < shapes[i].size(); j++){
            int s = shapes[i].size();
            if (doIntersect(src, tar, shapes[i][j % s], shapes[i][(j + 1) % s]))
                c = true;
        }

        cnt += c;
	}

	printf("%d\n", cnt);
}
