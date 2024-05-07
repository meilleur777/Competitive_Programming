#include <bits/stdc++.h>
using namespace std;

//Bruteforce
bool solution(vector<string> v) {
    
    set<string> st;
    for (auto i:v) st.insert(i);
    for (int i=0; i<(int)v.size(); i++) {
        string s=v[i];
        for (int j=1; j<(int)s.size(); j++) {
            string t=s.substr(0, j);
            if (st.find(t)!=st.end()) {
                return false;
            }
        }
    }

    return true;
}