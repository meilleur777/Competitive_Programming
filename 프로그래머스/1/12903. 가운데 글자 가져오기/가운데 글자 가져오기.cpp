#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    string ret="";
    int n=(int)s.size();
    for (int i=(n-1)/2; i<=n/2; i++) {
        ret.push_back(s[i]);
    }
    return ret;
}