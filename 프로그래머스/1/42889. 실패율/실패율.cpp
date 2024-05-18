#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<int> stages) {
    vector<int> endStageCnt(n+2, 0);
    for (auto i:stages) endStageCnt[i]++;
    vector<vector<long long>> failRate;
    for (int i=n; i>=1; i--) {
        int tmp=endStageCnt[i]+endStageCnt[i+1];
        if (tmp==0) failRate.push_back({0, 1, i});
        else failRate.push_back({endStageCnt[i], tmp, i});
        endStageCnt[i]=tmp;
    }
    sort(failRate.begin(), failRate.end(), [](const vector<long long>& p, const vector<long long>& q) -> bool { 
        if (p[0]*q[1]==q[0]*p[1]) {
            return p[2]<q[2];
        }
        return p[0]*q[1]>q[0]*p[1];
    });
    
    vector<int> ret;
    for (auto i:failRate) ret.push_back(i[2]);
    return ret;
}