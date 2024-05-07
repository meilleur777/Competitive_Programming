#include <bits/stdc++.h>
using namespace std;

//Stack
vector<int> solution(vector<int> v) {

    v.push_back(-1); //infinite value
    int n=v.size();
    
    stack<int> sk;
    vector<int> ret(n);
    for (int i=0; i<n; i++) {
        while (!sk.empty() && v[sk.top()]>v[i] ) {
            ret[sk.top()]=i-sk.top();
            if (v[i]==-1) ret[sk.top()]+=v[i];
            sk.pop();
        }
        sk.push(i);
    }

    ret.pop_back(); //remove infinite value
    return ret;
}