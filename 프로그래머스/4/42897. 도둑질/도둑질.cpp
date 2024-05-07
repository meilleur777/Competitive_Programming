#include <bits/stdc++.h>
using namespace std;

//dynamic programming
int solution(vector<int> v) {

    int n=v.size();
    vector<vector<int>> cache(2, vector<int>(n, -1));

    //cache[0] -> rob house[0] | cache[1] -> don't rob house[0]
    cache[0][0]=v[0], cache[0][1]=v[0];
    cache[1][0]=0, cache[1][1]=v[1];

    for (int i=2; i<n-1; i++) {
        for (int j=0; j<2; j++) {
            cache[j][i]=max(cache[j][i-2]+v[i], cache[j][i-1]);
            cache[j][i]=max(cache[j][i], cache[j][i-1]);
        }
    }
    cache[0][n-1]=cache[0][n-2];
    cache[1][n-1]=max(cache[1][n-3]+v[n-1], cache[1][n-2]);

    return max(cache[0][n-1], cache[1][n-1]);
}