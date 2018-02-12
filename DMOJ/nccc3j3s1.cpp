#include <bits/stdc++.h>

using namespace std;

string str;
int freq[26];
vector<int> shit;

int main() {
    cin >> str;
    for (char c : str) freq[c - 'a']++;
    for (int i = 0; i < 26; i++) shit.push_back(freq[i]);

    sort(shit.begin(), shit.end());

    int ans = 0;
    for (int i = 0; i < max((int) shit.size() - 2, 0); i++) {
        ans += shit[i];
    }

    cout << ans << endl;
}
