#include <bits/stdc++.h>
using namespace std;

//Greedy
int solution(vector<vector<int>> routes) {

    int n=routes.size();
    sort(routes.begin(), routes.end(), 
        [](const vector<int>& p, const vector<int>& q) -> bool {
            if (p[1]==q[1]) return p[0]<q[0];
            return p[1]<q[1];
    });

    int ret=1;
    int now=routes[0][1];
    int ptr=1;
    while (ptr<n) {
        while (ptr<n && routes[ptr][0]<=now && now<=routes[ptr][1]) {
            ptr++;
        }
        if (ptr<n) {
            now=routes[ptr][1];
            ret++;
        }
    }
    
    return ret;
}