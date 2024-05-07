#include <bits/stdc++.h>
using namespace std;

//Map
string solution(vector<string> par, vector<string> com) {
    map<string, int> mp;
    for (auto s:com) {
        mp[s]++;
    }
    for (auto s:par) {
        mp[s]--;
    }
    for (auto [p, q]:mp) {
        if (q!=0) return p;
    }
}
