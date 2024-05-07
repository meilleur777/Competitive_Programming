#include <bits/stdc++.h>
using namespace std;

//implement tree with nodes in coordinate plane
//node can be determined whether it is kid of node A 
//using coordinates of A and ancesters of A
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {

    const int n=nodeinfo.size();
    for (int i=1; i<=n; i++) {
        nodeinfo[i-1].push_back(i);
    }

    //[0]->x, [1]->y, [2]->number
    sort(nodeinfo.begin(), nodeinfo.end(), [&](vector<int> p, vector<int> q) -> bool {
        if (p[1]==q[1]) return p[0]<q[0];
        return p[1]>q[1];
    });

    vector<vector<int>> kid(n, vector<int>(2, -1));
    //bound[A] := {biggest x value of all ancesters of A less than x value of A
    //           , smallest x value of all ancesters of A bigger than x value of A}
    //if there is no such ancester, filled with negative/positive infinity
    vector<pair<int, int>> bound(n, {-1, 0x3f3f3f3f});

    int nxt=1;
    for (int now=0; now<n; now++) {
        if (nxt>=n || now>=nxt) continue;
        if (bound[now].first<nodeinfo[nxt][0] && nodeinfo[nxt][0]<nodeinfo[now][0]) {
            kid[now][0]=nxt;
            bound[nxt].first=bound[now].first;
            bound[nxt].second=nodeinfo[now][0];
            nxt++;
        }

        if (nxt>=n || now>=nxt) continue;
        if (nodeinfo[nxt][0]<bound[now].second && nodeinfo[now][0]<nodeinfo[nxt][0]) {
            kid[now][1]=nxt;
            bound[nxt].first=nodeinfo[now][0];
            bound[nxt].second=bound[now].second;
            nxt++;
        }
    }

    vector<vector<int>> ret(2);

    //preorder traverse
    function<void(int)> pre=[&](int now) {
        ret[0].push_back(nodeinfo[now][2]);
        if (kid[now][0]!=-1) pre(kid[now][0]);
        if (kid[now][1]!=-1) pre(kid[now][1]);
    };
    pre(0);

    //postorder traverse
    function<void(int)> post=[&](int now) {
        if (kid[now][0]!=-1) post(kid[now][0]);
        if (kid[now][1]!=-1) post(kid[now][1]);
        ret[1].push_back(nodeinfo[now][2]);
    };
    post(0);

    return ret;
}