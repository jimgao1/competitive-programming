#include <bits/stdc++.h>

using namespace std;

long long numbers, query, num[100001], sum[100001];

//Adds 'val' to the ith index
void add(int i, int val){
    while(i <= 100001){
        bit[i] += val;
        i += (-i & i);
    }
}

//Sums from index 0 to index 'i', inclusive
long long sum(int i){
    long long sum = 0;

    while(i > 0){
        sum += bit[i];
        i -= (i & -i);
    }

    return sum;
}

int main(){
    
    //BIT operations go here
    return 0;
}
