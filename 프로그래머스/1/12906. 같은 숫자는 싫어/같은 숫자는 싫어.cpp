#include <bits/stdc++.h>
using namespace std;

//Stack
vector<int> solution(vector<int> v) {

    vector<int> ret;
    int n=v.size();
    int ptr=0;
    while (ptr<n) {
        if (ret.empty() || v[ptr]!=ret.back()) {
            ret.push_back(v[ptr]);
            ptr++;
        }
        while (ptr<n && ret.back()==v[ptr]) ptr++;
    }
    
    return ret;
}