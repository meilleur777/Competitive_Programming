#include <bits/stdc++.h>
using namespace std;

int solution(int a, int b, int now) {
    int ret=0;
    while (now>=a) {
        ret+=now/a*b;
        now=now%a+now/a*b;
    }
    return ret;
}