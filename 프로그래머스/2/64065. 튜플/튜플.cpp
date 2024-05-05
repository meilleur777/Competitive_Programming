#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string s) {
    int n=s.length();
    vector<vector<int>> parsedS(505);

    int ptr=0;
    while (true) {
        while (ptr<n && !(s[ptr]>='0' && s[ptr]<='9')) ptr++;
        if (ptr>=n) break;

        vector<int> vt;
        while (true) {
            string tmp;
            while (s[ptr]>='0' && s[ptr]<='9') {
                tmp+=s[ptr];
                ptr++;
            }
            if (!tmp.empty()) vt.push_back(stoi(tmp));

            if (s[ptr]=='}') break;
            else if (s[ptr]==',') ptr++;
        }

        if (!vt.empty()) parsedS[(int)vt.size()-1]=vt;
    }

    set<int> st;
    vector<int> ret;
    for (auto v:parsedS) {
        for (auto str:v) {
            if (st.find(str)==st.end()) {
                ret.push_back(str);
                st.insert(str);
                break;
            }
        }
    }

    return ret;
}

