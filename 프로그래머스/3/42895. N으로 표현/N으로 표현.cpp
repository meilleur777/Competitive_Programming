#include <bits/stdc++.h>
using namespace std;

//dynamic programming
//cache[k] := set of possible result using k number of N
//cache[k] == cache[1] compute with cache[k-2],
//            cache[2] compute with cache[k-3]...
int solution(int n, int m) {
    vector<set<int>> cache(9);

    //result using only k
    //ex)n=5 => 5, 55, 555...
    int tmp=0;
    for (int i=0; i<8; i++) {
        tmp+=n*((int)pow(10, i));
        cache[i+1].insert(tmp);
    }

    for (int cost=2; cost<=8; cost++) {
        for (auto p:cache[cost-1]) {
            cache[cost].insert(p+n);
            cache[cost].insert(p-n);
            cache[cost].insert(p*n);
            cache[cost].insert(p/n);
        }
        for (int j=1; j<=cost-1; j++) {
            int left=j, right=cost-j;

            for (auto p:cache[left]) {
                for (auto q:cache[right]) {
                    cache[cost].insert(p+q);
                    cache[cost].insert(p-q);
                    cache[cost].insert(p*q);
                    if (q!=0) cache[cost].insert(p/q);
                }
            }
        }
    }

    for (int i=1; i<9; i++) {
        if (cache[i].find(m)!=cache[i].end()) {
            return i;
        }
    }

    return -1;
}   