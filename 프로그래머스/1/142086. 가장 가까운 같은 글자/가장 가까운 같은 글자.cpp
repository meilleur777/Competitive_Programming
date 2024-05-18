#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    vector<int> mem(26, -1);
    vector<int> ret;
    for (int i=0; i<(int)s.size(); i++) {
        if (mem[s[i]-'a']==-1) ret.push_back(-1);
        else ret.push_back(i-mem[s[i]-'a']);
        mem[s[i]-'a']=i;
    }
    return ret;
}