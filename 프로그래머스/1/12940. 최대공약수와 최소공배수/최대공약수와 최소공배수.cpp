#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, int m) {
    function<int(int, int)> gcd=[&](int a, int b) {
        if (a%b==0) return b;
        return gcd(b, a%b);
    };
    vector<int> ret;
    int gcdnm=gcd(max(n, m), min(n, m));
    ret.push_back(gcdnm);
    ret.push_back(n*m/gcdnm);
    return ret;
}