#include <bits/stdc++.h>
using namespace std;

bool solution(string s) {
    int n=s.size();
    if (n!=4 && n!=6) return false;
    for (auto c:s) {
        if (isalpha(c)) return false;
    }
    return true;
}