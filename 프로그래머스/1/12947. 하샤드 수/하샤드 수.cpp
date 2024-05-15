#include <bits/stdc++.h>
using namespace std;

bool solution(int x) {
    string s=to_string(x);
    int denom=0;
    for (auto c:s) {
        denom+=c-'0';
    }
    
    return (x%denom==0);
}