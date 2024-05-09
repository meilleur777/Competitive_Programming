#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
    int n=s.size();
    return string(n-4, '*')+s.substr(n-4);
}