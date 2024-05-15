#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr) {
    int mn=*min_element(arr.begin(), arr.end());
    vector<int> ret;
    for (auto i:arr) {
        if (i!=mn) ret.push_back(i);
    }
    if (ret.empty()) ret.push_back(-1);
    return ret;
}