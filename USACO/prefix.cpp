/*
ID: jim_yub1
LANG: C++11
TASK: prefix
*/

/*
	IOI 1996 - Longest Prefix
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define USACO
#define FILEIN "prefix.in"
#define FILEOUT "prefix.out"

using namespace std;

vector<string> primitives;
string str;

bool dp[210000];

int longestPrefix(){
	/*
		An Dynamic Programming Approach:
			I am marking indexes that are possible to be reached using
			the existing primitives, and to get the longest prefix, I
			simply need to find the farthest point my dp array can
			"reach".
	*/

	for (int i = 0; i < 210000; i++)
		dp[i] = false;

	/*
		Start by marking primitives starting from index 0
	*/

	for (int i = 0; i < primitives.size(); i++){
		if (primitives[i].length() > str.length()) continue;

		if (str.substr(0, primitives[i].length()) == primitives[i])
			dp[primitives[i].length()] = true;
	}

	/*
		Start marking reachable indexes by iterating through array
		(I mean string)
	*/

	for (int i = 0; i <= str.length(); i++){
		/*
			Check if the current index is already reached, if not,
			there is no point of doing further calculations
		*/
		if (dp[i]){
			for (int j = 0; j < primitives.size(); j++){
				/*
					Check if the primitives match the current string starting
					with index i
				*/

				if (i + primitives[j].length() > str.length()) continue;

				if (str.substr(i, primitives[j].length()) == primitives[j])
					dp[i + primitives[j].length()] = true;
			}
		}
	}

	/*
		Calculating the furthest index
	*/

	int maxLength = 0;

	for (int i = 0; i <= str.length(); i++)
		if (dp[i])
			maxLength = i;

	return maxLength;
}

int main(){
#ifdef USACO
	freopen(FILEIN, "r", stdin);
	freopen(FILEOUT, "w", stdout);
#endif

	while (true){
		string s;
		cin >> s;

		if (s == ".") break;

		primitives.push_back(s);
	}

	str = "";

    while(true){
        if (cin.eof()) break;
        string t;
        cin >> t;

        str += t;
    }

	int result = longestPrefix();
	cout << result << endl;

	return 0;
}
