#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> words) {
    vector<string> token({"aya", "ye", "woo", "ma"});
    // set<string> st;
    int ret=0;
    for (auto s:words) {
        bool canPronounce=true;
        string last="";
        for (int i=0; i<(int)s.size(); i++) {
            bool flag=false;
            for (auto t:token) {
                if (s.substr(i, (int)t.size())==t && last!=t) {
                    i+=(int)t.size()-1;
                    last=t;
                    flag=true;
                }
            }
            if (flag==false) {
                canPronounce=false;
                break;
            }
        }
        // if (canPronounce) st.insert(s);
        ret+=canPronounce;
    }
    return ret;
    // return (int)st.size();
}