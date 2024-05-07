#include <bits/stdc++.h>
using namespace std;

//bfs with nodes named with string
int solution(string s, string e, vector<string> w) {
    set<string> st;
    for (auto i:w) st.insert(i);

    queue<pair<string, int>> q;
    q.push({s, 0});
    set<string> vis;
    vis.insert(s);
    while (!q.empty()) {
        string now=q.front().first;
        int cost=q.front().second;
        q.pop();

        if (now==e) {
            return cost;
        }

        for (int i=0; i<(int)now.size(); i++) {
            for (int j=0; j<26; j++) {
                string nxt=now.substr(0, i)+char(j+'a');
                if (i<(int)now.size()-1) nxt+=now.substr(i+1);
                if (st.find(nxt)==st.end() || vis.find(nxt)!=vis.end()) continue;
                vis.insert(nxt);
                q.push({nxt, cost+1});
            }
        }
    }
    
    return 0;
}