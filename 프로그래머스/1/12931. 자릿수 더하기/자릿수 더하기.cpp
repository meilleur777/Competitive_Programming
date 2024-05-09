#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    string s=to_string(n);
    int ret=0;
    for (auto c:s) {
        ret+=c-'0';
    }
    return ret;
}