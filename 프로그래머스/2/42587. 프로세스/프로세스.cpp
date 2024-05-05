#include <bits/stdc++.h>
using namespace std;

//Priority Queue
int solution(vector<int> pri, int location) {

    int n=pri.size();

    priority_queue<int> pq;
    for (auto i:pri) pq.push(i);

    int ret=1;
    queue<int> q;
    for (int i=0; i<n; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        int now=q.front();
        q.pop();
        if (pq.top()>pri[now]) {
            q.push(now);
        }
        else {
            if (now==location) return ret;
            pq.pop();
            ret++;
        }
    }

    return -1;
}