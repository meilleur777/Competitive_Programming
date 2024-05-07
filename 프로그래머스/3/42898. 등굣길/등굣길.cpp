#include <bits/stdc++.h>
using namespace std;

//dynamic programming
int solution(int m, int n, vector<vector<int>> water) {
    const long long inf=1e9+7;

    set<pair<int, int>> forbid;
    for (auto v:water) {
        forbid.insert({v[1]-1, v[0]-1});
    }
    
    vector<vector<long long>> cache(n, vector<long long>(m, 0));
    cache[0][0]=1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (forbid.find({i, j})!=forbid.end()) continue;

            if (i>0) cache[i][j]+=cache[i-1][j];
            if (j>0) cache[i][j]+=cache[i][j-1];
            cache[i][j]=cache[i][j]%inf;
        }
    }

    return cache[n-1][m-1];
}