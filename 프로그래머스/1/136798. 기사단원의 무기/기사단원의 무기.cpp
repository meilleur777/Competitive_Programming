#include <bits/stdc++.h>
using namespace std;

int solution(int number, int limit, int power) {
    int ret=0;
    for (int i=1; i<=number; i++) {
        set<int> factor;
        for (int j=1; j*j<=i; j++) {
            if (i%j==0) {
                factor.insert(j);
                factor.insert(i/j);
            }
        }
        
        int factNum=factor.size();
        if (factNum>limit) ret+=power;
        else ret+=factNum;
    }
    return ret;
}