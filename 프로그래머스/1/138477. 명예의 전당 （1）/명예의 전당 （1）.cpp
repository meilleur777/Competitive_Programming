#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> ret;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i:score) {
        if ((int)pq.size()<k) {
            pq.push(i);
        }
        else if (pq.top()<i) {
            pq.pop();
            pq.push(i);
        }
        ret.push_back(pq.top());
    }
    return ret;
}