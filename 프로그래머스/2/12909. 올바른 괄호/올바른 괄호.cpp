#include <bits/stdc++.h>
using namespace std;

//Stack
bool solution(string s) {
    
    int n=s.size();
    stack<char> sk;
    for (int i=0; i<n; i++) {
        if (s[i]=='(') {
            sk.push(s[i]);
        }
        else {
            if (sk.empty() || sk.top()==')') return false;
            sk.pop();
        }
    }

    if (!sk.empty()) return false;
    return true;
}
