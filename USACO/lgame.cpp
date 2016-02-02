/*
  ID: jim_yub1
  LANG: C++11
  TASK: lgame
*/

#include <bits/stdc++.h>

using namespace std;

int letters[26], maxValue = 0;
string text;
vector<string> dict;

vector<pair<int, pair<string, string> > > possible;

//values of the letters
int values[] = {2, 5, 4, 4, 1, 6, 5, 5, 1, 7, 6, 3, 5, 2, 3, 5, 7, 2, 1, 2, 4, 6, 6, 7, 5, 7};

/*
  s1: the word read from the user
  s2: the word in the dictionary

*/
bool checkWord(string s1, string s2){
  memset(letters, 0, sizeof letters);
  for (int i = 0; i < s1.length(); i++) letters[s1[i] - 'a'] ++;
  for (int i = 0; i < s2.length(); i++) letters[s2[i] - 'a'] --;

  for (int i = 0; i < 26; i++) if (letters[i] < 0) return false;
  return true;
}

bool checkWord(string src, string s1, string s2){
  memset(letters, 0, sizeof letters);
  for (int i = 0; i < src.length(); i++) letters[src[i] - 'a'] ++;
  for (int i = 0; i < s1.length(); i++) letters[s1[i] - 'a'] --;
  for (int i = 0; i < s2.length(); i++) letters[s2[i] - 'a'] --;

  for (int i = 0; i < 26; i++) if (letters[i] < 0) return false;
  return true;
}

//calculates the value of a word
int calcValue(string word){
  int w = 0;
  for (char c : word) w += values[c - 'a'];

  return w;
}

int main(){
  freopen("lgame.in", "r", stdin);
  freopen("lgame.out", "w", stdout);

  cin >> text;

  ifstream dictfile;
  dictfile.open("lgame.dict");

  while(true){
    string cur;
    dictfile >> cur;

    if (cur == ".") break;
       
    if (checkWord(text, cur)) dict.push_back(cur);	  
  }

  for (int i = 0; i < dict.size(); i++){

    possible.push_back({ calcValue(dict[i]), { dict[i], "" } });
    maxValue = max(maxValue, calcValue(dict[i]));

    for (int j = 0; j < dict.size(); j++){
      if (i == j) continue;

      if (checkWord(text, dict[i], dict[j])){
	if (dict[j] < dict[i]){
	  //break;
	}

	possible.push_back({ calcValue(dict[i]) + calcValue(dict[j]), {dict[i], dict[j]} });
	maxValue = max(maxValue, calcValue(dict[i]) + calcValue(dict[j]));
      }

    }
  }

  sort(possible.begin(), possible.end());
  //possible.erase(unique(possible.begin(), possible.end()), possible.end());

  printf("%d\n", maxValue);

  for (int i = 0; i < possible.size(); i++){
    if (possible[i].first != maxValue) continue;

    if (possible[i].second.second == "")
      printf("%s\n", possible[i].second.first.c_str());
    else{
      if (possible[i].second.first > possible[i].second.second) continue;

      printf("%s %s\n", possible[i].second.first.c_str(), possible[i].second.second.c_str());
    }
  }
}
