#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> v) {
    vector<int> cnt(3, 0);
    vector<vector<int>> ans({
        {1, 2, 3, 4, 5},
        {2, 1, 2, 3, 2, 4, 2, 5},
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    });
    for (int i=0; i<(int)v.size(); i++) {
        for (int j=0; j<3; j++) {
            int tmp=ans[j][i%(int)ans[j].size()];
            cnt[j]+=tmp==v[i];
        }
    }

    vector<int> ret;
    int mx=*max_element(cnt.begin(), cnt.end());
    for (int i=0; i<3; i++) {
        if (mx==cnt[i]) {
            ret.push_back(i+1);
        }
    }
    
    return ret;
}