#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> v) {
    
    int ret=0;
    int n=v.size();
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            for (int k=j+1; k<n; k++) {
                if (v[i]+v[j]+v[k]==0) ret++;
            }
        }
    }
    
    return ret;
}