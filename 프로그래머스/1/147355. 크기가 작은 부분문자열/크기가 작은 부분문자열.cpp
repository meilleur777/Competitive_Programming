#include <bits/stdc++.h>
using namespace std;

int solution(string t, string p) {
    int n=t.size(), m=p.size();
    int ret=0;
    for (int i=0; i+m-1<n; i++) {
        string tmp=t.substr(i, m);
        if (tmp<=p) ret++;
    }
    return ret;
}