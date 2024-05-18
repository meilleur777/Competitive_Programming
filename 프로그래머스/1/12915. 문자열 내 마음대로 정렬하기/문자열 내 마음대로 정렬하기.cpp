#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> v, int n) {
    sort(v.begin(), v.end(), [&](const string& p, const string& q) -> bool {
        if (p[n]==q[n]) return p<q;
        return p[n]<q[n];
    });
    return v;
}