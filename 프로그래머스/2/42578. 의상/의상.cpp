#include <bits/stdc++.h>
using namespace std;

//Combinatorics
int solution(vector<vector<string>> v) {
    
    map<string, int> mp;
    for (auto c:v) {
        mp[c[1]]++;
    }
    int ret=1;
    for (auto [p, q]:mp) {
        ret*=(q+1);
    }

    return ret-1;
}