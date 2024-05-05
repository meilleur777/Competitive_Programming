#include <bits/stdc++.h>
using namespace std;

//Greedy
int solution(vector<int> people, int limit) {
    
    sort(people.begin(), people.end());
    deque<int> dq;
    for (auto i:people) {
        dq.push_back(i);
    }

    int ret=0;
    while (!dq.empty()) {
        int a=dq.front();
        dq.pop_front();
        if (dq.empty()) {
            ret++;
            break;
        }
        else {
            while (!dq.empty() && dq.back()+a>limit) {
                ret++;
                dq.pop_back();
            }
            if (!dq.empty()) dq.pop_back();
            ret++;
        }
    }

    return ret;
}
