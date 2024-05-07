#include <bits/stdc++.h>
using namespace std;

//Backtracking
vector<string> solution(vector<vector<string>> edges) {
    map<string, vector<pair<string, bool>>> mp;
    for (auto edge:edges) {
        mp[edge[0]].push_back({edge[1], true});
    }

    for (auto& [p, q]:mp) {
        sort(q.begin(), q.end(), 
            [](const pair<string, bool>& a, const pair<string, bool>& b)  -> bool { 
                return a.first<b.first; 
        });
    }

    vector<string> ret;
    function<bool(string)> dfs=[&](string now) {
        ret.push_back(now);
        if ((int)ret.size()==(int)edges.size()+1) {
            return true;
        }

        for (auto& p:mp[now]) {
            if (p.second==false) continue;
            string nxt=p.first;
            p.second=false;
            if (dfs(nxt)==true) {
                return true;
            }
            else {
                p.second=true;
            }
        }

        ret.pop_back();
        return false;
    };
    dfs("ICN");

    return ret;
}