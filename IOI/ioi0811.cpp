
#include <bits/stdc++.h>

#define INF 0x3f3f3f3f


using namespace std;

int N, cnt = 1, ans = 0, w = 0, trie[500001][26];
char t[500001];
bool marked[500001], e[500001];

vector<string> words;

vector<char> o;

bool comp(string a, string b) { return a.length() < b.length(); }

int create_node(){
    return cnt++;
}

void build(int current, string word, bool mark){
    if (word.length() > 0){
        if (trie[current][word[0] - 'a'] == INF)
            trie[current][word[0] - 'a'] = create_node();
        t[trie[current][word[0] - 'a']] = word[0];
        build(trie[current][word[0] - 'a'], word.substr(1), mark);
        marked[trie[current][word[0] - 'a']] = mark;
    } else {
        e[current] = true;
    }
}

void dfs(int current){
    ans++;

    o.push_back(t[current]);
    if (e[current]) o.push_back('P');
    for (int i = 0; i < 26; i++){
        if (trie[current][i] != INF && !marked[trie[current][i]]){
            dfs(trie[current][i]);

        }
    }

    for (int i = 0; i < 26; i++){
        if (trie[current][i] != INF && marked[trie[current][i]]){
            dfs(trie[current][i]);

        }
    }

    if (!marked[current]) o.push_back('-');
}

int main(){
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // LOCAL

    memset(trie, 0x3f, sizeof trie);

    cin >> N;
    for (int i = 0; i < N; i++){
        string asd;
        cin >> asd;

        words.push_back(asd);
    }

    sort(words.begin(), words.end(), comp);
    for (int i = 0; i < words.size() - 1; i++)
        build(0, words[i], false);
    build(0, words[words.size() - 1], true);

    dfs(0);

    cout << o.size() - 2 << "\n";
    for (int i = 1; i < o.size() - 1; i++) cout << o[i] << "\n";
}
