#include <bits/stdc++.h>
using namespace std;

//Greedy
int solution(vector<int> v, int k) {

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto i:v) pq.push(i);

    int ret=0;
    while (pq.size()>=2 && pq.top()<k) {
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        pq.push(a+2*b);
        ret++;
    }
    if (!pq.empty() && pq.top()<k) return -1;
    
    return ret;
}