#include <bits/stdc++.h>

#define tsize 1000
#define INF 0x3f3f3f3f

using namespace std;

struct trie{

    int cur = 1, tdata[tsize][26];
    char tchar[tsize];
    bool e[tsize];

    trie(){ memset(tdata, 0x3f, sizeof tdata); }

    int create_node() { return cur++; }

    void insert_word(int current, string word){
        if (word.length() > 0){
            //if node not created, then create node
            if (tdata[current][word[0] - 'A'] == INF)
                tdata[current][word[0] - 'A'] = create_node();

            //update data for the children
            tchar[tdata[current][word[0] - 'A']] = word[0];
            insert_word(tdata[current][word[0] - 'A'], word.substr(1));
        }
    }

    bool search_word(int current, string word){
        if (word.length() == 0) return true;
        return search_word(tdata[current][word[0] - 'A'], word.substr(1));
    }
};

int main(){
    trie* t = new trie();

    string str;
    while(cin >> str;){
        t->insert_word(0, str);
    }
    cout << t->cur << endl;
}

