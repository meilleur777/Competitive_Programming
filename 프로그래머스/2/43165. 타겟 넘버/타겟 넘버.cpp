#include <bits/stdc++.h>
using namespace std;

// bruteforce using bitmask
int solution(vector<int> numbers, int target) {
    int ret=0;
    int n=numbers.size();
    for (int i=0; i<(1<<n); i++) {
        int tmp=0;
        for (int j=0; j<n; j++) {
            if ((i&(1<<j))) tmp+=numbers[j];
            else tmp-=numbers[j];
        }
        if (tmp==target) ret++;
    }
    
    return ret;
}