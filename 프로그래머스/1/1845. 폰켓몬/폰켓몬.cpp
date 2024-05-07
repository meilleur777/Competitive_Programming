#include <bits/stdc++.h>
using namespace std;

//Data Structure
int solution(vector<int> v) {
    map<int, int> mp;
    for (auto i:v) {
        mp[i]++;
    }
    
    return min((int)v.size()/2, (int)mp.size());
}