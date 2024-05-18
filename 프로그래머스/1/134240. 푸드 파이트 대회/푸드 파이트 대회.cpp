#include <bits/stdc++.h>
using namespace std;

string solution(vector<int> food) {
    string ret = "";
    int n=food.size();
    for (int i=1; i<n; i++) {
        ret+=string(food[i]/2, char(i+'0'));
    }
    ret.push_back('0');
    int m=ret.size();
    for (int i=m-2; i>=0; i--) {
        ret.push_back(ret[i]);
    }
    return ret;
}