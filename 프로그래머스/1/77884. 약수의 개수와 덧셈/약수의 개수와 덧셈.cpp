#include <bits/stdc++.h>
using namespace std;

int solution(int left, int right) {
    int ret=0;
    for (int now=left; now<=right; now++) {
        bool flag=false;
        for (int j=1; j*j<=now; j++) {
            if (j*j==now) {
                flag=true;
                break;
            }
        }
        
        if (flag) ret-=now;
        else ret+=now;
    }
    return ret;
}