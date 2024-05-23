#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    set<int> st;
    for (auto i:win_nums) st.insert(i);
    int cnt=0, cnt0=0;
    for (auto i:lottos) {
        cnt+=st.find(i)!=st.end();
        cnt0+=(i==0);
    }
    vector<int> ret({min(7-(cnt+cnt0), 6), min(7-cnt, 6)});
    return ret;
}