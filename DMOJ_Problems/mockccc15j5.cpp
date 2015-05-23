
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<unsigned long, unsigned long>> vectx;
vector<pair<unsigned long, unsigned long>> vecty;


int main(){
	unsigned long b;
	cin >> b;

	for (int i = 0; i < b; i++){
		unsigned long x, y;
		cin >> x >> y;

		vectx.push_back(make_pair(x, y));
		vecty.push_back(make_pair(y, x));
	}

	sort(vectx.begin(), vectx.end());
	sort(vecty.begin(), vecty.end());

	unsigned long o;
	cin >> o;

	unsigned long long ans = 0;
	unsigned long px, py;

	cin >> px >> py;

	for (int i = 0; i < o - 1; i++){
		unsigned long cx, cy;
		cin >> cx >> cy;

		if (cy == py){
			ans += upper_bound(vecty.begin(), vecty.end(), make_pair(cy, max(cx, px))) -
				lower_bound(vecty.begin(), vecty.end(), make_pair(cy, min(cx, px)));

		}
		else {

			ans += upper_bound(vectx.begin(), vectx.end(), make_pair(cx, max(cy, py))) -
				lower_bound(vectx.begin(), vectx.end(), make_pair(cx, min(cy, py)));

		}

		px = cx, py = cy;
	}

	cout << ans << endl;

	system("pause");
	return 0;
}
