#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> v) {
    vector<int> ret;
    set<int> st;
    int n=v.size();
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            st.insert(v[i]+v[j]);
        }
    }
    for (auto p:st) ret.push_back(p);
    return ret;
}