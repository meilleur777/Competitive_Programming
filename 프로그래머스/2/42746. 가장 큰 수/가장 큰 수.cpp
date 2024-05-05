#include <bits/stdc++.h>
using namespace std;

//Greedy
string solution(vector<int> numbers) {

    string ret = "";
    vector<string> n;
    for (auto i:numbers) {
        n.push_back(to_string(i));
    }
    sort(n.begin(), n.end(), [&](const string& p, const string& q) -> bool {
        return p+q>q+p;
    });

    for (auto i:n) ret+=i;
    int ptr=0;
    while (ret[ptr]=='0' && ptr<(int)ret.length()-1) {
        ptr++;
    }
    ret=ret.substr(ptr);

    return ret;
}