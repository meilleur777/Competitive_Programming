#include <bits/stdc++.h>
using namespace std;

//Priority Queue
vector<int> solution(vector<string> operations) {

    priority_queue<int> mxq, erasemxq;
    priority_queue<int, vector<int>, greater<int>> mnq, erasemnq;

    for (auto ope:operations) {
        char o=ope[0];
        string nums=ope.substr(2);
        int num=stoi(nums);

        if (o=='I') {
            mxq.push(num);
            mnq.push(num);
        }
        else if (o=='D') {
            if (num==1) {
                while (erasemxq.empty()==false && erasemxq.top()==mxq.top()) {
                    mxq.pop();
                    erasemxq.pop();
                }
                if (mxq.empty()==true) continue;
                erasemnq.push(mxq.top());
                mxq.pop();
            }
            else if (num==-1) {
                while (erasemnq.empty()==false && erasemnq.top()==mnq.top()) {
                    mnq.pop();
                    erasemnq.pop();
                }
                if (mnq.empty()==true) continue;
                erasemxq.push(mnq.top());
                mnq.pop();
            }
        }
    }

    while (erasemxq.empty()==false && erasemxq.top()==mxq.top()) {
        mxq.pop();
        erasemxq.pop();
    }
    while (erasemnq.empty()==false && erasemnq.top()==mnq.top()) {
        mnq.pop();
        erasemnq.pop();
    }

    vector<int> ret;
    if (mxq.empty()) {
        ret={0, 0};
    }
    else {
        ret={mxq.top(), mnq.top()};
    }

    return ret;
}