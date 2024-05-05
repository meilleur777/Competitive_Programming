#include <bits/stdc++.h>
using namespace std;

//Sort
vector<int> solution(vector<string> g, vector<int> p) {
    
    int n=g.size();
    map<string, int> mp;
    for (int i=0; i<n; i++) {
        mp[g[i]]+=p[i];
    }
    vector<tuple<int, string, int>> v(n);
    for (int i=0; i<n; i++) {
        v[i]=make_tuple(i, g[i], p[i]);
    }

    sort(v.begin(), v.end(), 
        [&](const tuple<int, string, int>& a, const tuple<int, string, int>& b) -> bool {
        if (get<1>(a)==get<1>(b)) {
            if (get<2>(a)==get<2>(b)) {
                return get<0>(a)<get<0>(b);
            }
            else {
                return get<2>(a)>get<2>(b);
            }
        }
        else {
            return mp[get<1>(a)]>mp[get<1>(b)];
        }
    });

    int ptr=0;
    int cnt=0;
    string ng=get<1>(v[ptr]);
    vector<int> ret;
    while (ptr<n) {
        while (cnt<2 && ptr<n && ng==get<1>(v[ptr])) {
            ret.push_back(get<0>(v[ptr]));
            ptr++;
            cnt++;
        }
        cnt=0;
        while (ptr<n && ng==get<1>(v[ptr])) ptr++;
        if (ptr<n) ng=get<1>(v[ptr]);
    }

    return ret;
}