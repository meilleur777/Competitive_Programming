#include <bits/stdc++.h>
using namespace std;

//Greedy
//depart truck as soon as it can be
int solution(int blen, int w, vector<int> t) {
    int n=t.size();

    //number, position
    deque<pair<int, int>> q;

    function<int(void)> getweight=[&]() {
        int ret=0;
        if (!q.empty()) {
            for (auto i:q) {
                ret+=t[i.first];
            }
        }
        return ret;
    };

    int ret=1;
    q.push_back({0, 1});
    for (int i=1; i<n; i++) {
        while (!q.empty() && getweight()+t[i]>w) {
            int tmp=q.front().second;
            tmp=blen-tmp+1;
            ret+=tmp;
            q.pop_front();
            if (!q.empty()) {
                for (auto& qq:q) {
                    qq.second+=tmp;
                }
            }
        }
        if (!q.empty() && q.back().second==1) {
            int tmp=1;
            ret+=tmp;
            if (!q.empty()) {
                for (auto& qq:q) {
                    qq.second+=tmp;
                }
            }
        }
        while (!q.empty() && q.front().second>blen) q.pop_front();
        q.push_back({i, 1});
    }

    while (!q.empty()) {
        int tmp=q.front().second;
        tmp=blen-tmp+1 ;
        ret+=tmp;
        q.pop_front();
        if (!q.empty()) {
            for (auto& i:q) {
                i.second+=tmp;
            }
        }
    }
    
    return ret;
}
