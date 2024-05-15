#include <bits/stdc++.h>
using namespace std;

int solution(int num) {
    int cnt=0;
    long long lnum=num;
    while (lnum!=1 && cnt<500) {
        if (lnum%2==0) lnum/=2;
        else lnum=lnum*3+1;
        cnt++;
    }
    if (cnt==500 && lnum!=1) return -1;
    return cnt;
}