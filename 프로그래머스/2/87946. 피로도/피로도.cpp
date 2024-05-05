#include <bits/stdc++.h>
using namespace std;

int solution(int k, vector<vector<int>> d) {
    int n=d.size();
    vector<int> per;
    for (int i=0; i<n; i++) {
        per.push_back(i);
    }

    int ret=0;
    do {
        int now=k;
        for (int i=0; i<n; i++) {
            if (now<d[per[i]][0]) break;
            now-=d[per[i]][1];
            ret=max(ret, i+1);
        }
    } while (next_permutation(per.begin(), per.end()));

    return ret;
}