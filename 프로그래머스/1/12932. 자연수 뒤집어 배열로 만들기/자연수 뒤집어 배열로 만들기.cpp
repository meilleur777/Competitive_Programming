#include <bits/stdc++.h>
using namespace std;

vector<int> solution(long long n) {
    vector<int> ret;
    int nlen=to_string(n).size();
    for (int i=0; i<nlen; i++) {
        ret.push_back(n%10);
        n/=10;
    }
    return ret;
}