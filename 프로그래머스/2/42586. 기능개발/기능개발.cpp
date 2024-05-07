#include <bits/stdc++.h>
using namespace std;

//Implementation
vector<int> solution(vector<int> pro, vector<int> spe) {

    vector<int> ret;
    int n=pro.size();

    int ptr=0;
    for (int i=0; i<100; i++) {
        for (int j=0; j<n; j++) {
            pro[j]+=spe[j];
        }

        int cnt=0;
        while (ptr<n && pro[ptr]>=100) {
            cnt++;
            ptr++;
        }
        if (cnt) ret.push_back(cnt);
    }
    
    return ret;
}