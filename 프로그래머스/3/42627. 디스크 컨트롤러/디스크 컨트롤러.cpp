#include <bits/stdc++.h>
using namespace std;

//Greedy
//perform shortest job within set of jobs that can be started immediately
int solution(vector<vector<int>> v) {
    
    int n=v.size();
    auto cpr1=[&](int p, int q) {
        return v[p][0]>v[q][0];
    };
    auto cpr2=[&](int p, int q) {
        return v[p][1]>v[q][1];
    };

    priority_queue<int, vector<int>, decltype(cpr1)> pq1(cpr1);
    priority_queue<int, vector<int>, decltype(cpr2)> pq2(cpr2);

    for (int i=0; i<n; i++) {
        pq1.push(i);
    }

    int now=-1;
    int ret=0;
    while (!pq1.empty() || !pq2.empty()) {
        while (!pq1.empty() && v[pq1.top()][0]<=now) {
            pq2.push(pq1.top());
            pq1.pop();
        }
        if (pq2.empty() && !pq1.empty()) {
            now=v[pq1.top()][0];
        }
        else if (!pq2.empty()) {
            now+=v[pq2.top()][1];
            ret+=now-v[pq2.top()][0];
            pq2.pop();
        }
    }

    return ret/n;
}