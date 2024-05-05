#include <bits/stdc++.h>
using namespace std;

//dynamic programming
int solution(vector<vector<int>> v) {
    
    int n=v.size();

    for (int i=1; i<n; i++) {
        for (int j=0; j<=i; j++) {
            int tmp=v[i][j];
            if (j>0) tmp=max(tmp, v[i][j]+v[i-1][j-1]);
            if (j<i) tmp=max(tmp, v[i][j]+v[i-1][j]);
            v[i][j]=tmp;
        }
    }

    int ret=0;
    for (int i=0; i<n; i++){
        ret=max(ret, v[n-1][i]);
    }
    return ret;
}