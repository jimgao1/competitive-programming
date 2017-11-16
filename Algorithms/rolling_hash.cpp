
#include <bits/stdc++.h>

using namespace std;

struct RollingHash {
    long long val = 0;
    int MOD, EXP, MAX_LEN;
    deque<int> Q;
    vector<long long> pows;

    RollingHash(int mod, int exp, int max_len) {
        this->MOD = mod;
        this->EXP = exp;
        this->MAX_LEN = max_len;

        pows.push_back(1);
        while (pows.size() <= max_len) {
            pows.push_back((pows[pows.size() - 1] * EXP) % MOD);
        }
    }

    void push_back(int n) {
        Q.push_back(n);
        val = (val * EXP) % MOD;
        val = (val + n) % MOD;
    }

    void push_front(int n) {
        Q.push_front(n);
        long long tmp = (pows[Q.size() - 1] * n) % MOD;
        val = (val + tmp) % MOD;
    }

    void pop_front() {
        int e = Q.front();
        long long tmp = e * pows[Q.size() - 1] % MOD;
        val = (val - tmp + MOD) % MOD;

        Q.pop_front();
    }

    void pop_back() {
        // To be implemented
    }
};

int main() {

}
