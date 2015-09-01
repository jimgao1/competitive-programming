
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
            if (tdata[current][word[0] - 'a'] == INF)
                tdata[current][word[0] - 'a'] = create_node();

            //update data for the children
            tchar[tdata[current][word[0] - 'a']] = word[0];
            insert_word(tdata[current][word[0] - 'a'], word.substr(1));
        }
    }

    bool search_word(int current, string word){
        if (word.length() == 0) return true;
        return search_word(tdata[current][word[0] - 'a'], word.substr(1));
    }
};

int main(){
    trie* t = new trie();

    //insertion
    t->insert_word(0, "word1");
    t->insert_word(0, "word2");
    t->insert_word(0, "word3");

    //search
    bool b = t->search_word(0, "word1");
}
