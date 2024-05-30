#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> v, string t) {
    int n=v.size();
    int m=t.size();
    const int inf=0x3f3f3f3f;
    
    vector<int> cache(m, inf);
    for (int i=0; i<n; i++) {
        if (v[i][0]!=t[0]) continue;
        
        int wordSize=v[i].size();
        if (wordSize-1<m && v[i]==t.substr(0, wordSize)) {
            cache[wordSize-1]=min(cache[wordSize-1], 1);
        }
    }
    for (int i=0; i<m; i++) {
        if (cache[i]>=inf) continue;
        
        for (int j=0; j<n; j++) {
            if (v[j][0]!=t[i+1]) continue;
            int wordSize=v[j].size();
            if (i+wordSize<m && t.substr(i+1, wordSize)==v[j]) {
                cache[i+wordSize]=min(cache[i+wordSize], cache[i]+1);
            }
        }
    }
    
    if (cache[m-1]==inf) return -1;
    return cache[m-1];
}