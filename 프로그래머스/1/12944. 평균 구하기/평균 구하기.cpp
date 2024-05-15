#include <bits/stdc++.h>
using namespace std;

double solution(vector<int> arr) {
    double ret=0;
    for (auto i:arr) ret+=i;
    return ret/(int)arr.size();
}