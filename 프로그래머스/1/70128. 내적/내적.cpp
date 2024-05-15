#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> a, vector<int> b) {
    int n=a.size();
    int ret=0;
    for (int i=0; i<n; i++) {
        ret+=a[i]*b[i];
    }
    return ret;
}