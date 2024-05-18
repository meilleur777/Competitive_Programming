#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    vector<int> ternary;
    while (n) {
        ternary.push_back(n%3);
        n/=3;
    }
    int now=1;
    int ret=0;
    for (int i=(int)ternary.size()-1; i>=0; i--) {
        ret+=now*ternary[i];
        now*=3;
    }
    return ret;
}