#include <bits/stdc++.h>
using namespace std;

//Kruskal’s Minimum Spanning Tree Algorithm
//implemented using Union-Find algorithm
int solution(int n, vector<vector<int>> costs) {

    auto cpr=[&](const vector<int>& a, const vector<int>& b) {
        return a[2]>b[2];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cpr)> pq(cpr);
    for (auto v:costs) {
        pq.push(v);
    }

    vector<int> par(n);
    for (int i=0; i<n; i++) par[i]=i;
    function<int(int)> find=[&](int now) {
        if (par[now]==now) return now;
        return find(par[now]);
    };
    function<void(int, int)> merge=[&](int a, int b) {
        int aa=find(a);
        int bb=find(b);
        par[bb]=aa;
    };

    int cnt=0;
    int ret=0;
    while (!pq.empty() && cnt<n-1) {
        int a=pq.top()[0], b=pq.top()[1], c=pq.top()[2];
        pq.pop();
        if (find(a)!=find(b)) {
            merge(a, b);
            cnt++;
            ret+=c;
        }
    }

    return ret;
}