#include <bits/stdc++.h>
using namespace std;

string solution(string s, int n) {
    for (auto& c:s) {
        if (isupper(c)) c='A'+((c-'A'+n)%26);
        else if (islower(c)) c='a'+((c-'a'+n)%26);
    }
    return s;
}