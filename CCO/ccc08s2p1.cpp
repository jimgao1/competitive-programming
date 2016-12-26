
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> name;
vector<int> from, to;

int main(){
	int pCount;
	cin >> pCount;

	for (int i=0; i<pCount; i++){
		string n;
		int f, t;
		cin >> n >> f >> t;

		name.push_back(n);
		from.push_back(f);
		to.push_back(t);
	}


	vector<string> moved;

	while(!name.empty()){

		bool m = false;

		for (int i=0; i<name.size(); i++){
			bool free = true;
			for (int j=0; j<name.size(); j++){
				if (j != i)
					if (from[j] == to[i]) {
						free = false;
						break;
					}
			}

			if (free){
				moved.push_back(name[i]);
				name.erase(name.begin() + i);
				from.erase(from.begin() + i);
				to.erase(to.begin() + i);

				m = true;
			}
		}

		if (!m){
			cout << "Impossible" << endl;
			return 0;
		}
	}

	for (string s : moved)
		cout << s << endl;
}
