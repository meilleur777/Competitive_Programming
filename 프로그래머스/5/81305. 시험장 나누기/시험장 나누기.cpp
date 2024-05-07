#include <bits/stdc++.h>
using namespace std;

int solution(int k, vector<int> num, vector<vector<int>> links) {
    int n=num.size();

    int root=-1;
    vector<int> indegree(n, 0);
    for (auto link:links) {
        if (link[0]!=-1) indegree[link[0]]++;
        if (link[1]!=-1) indegree[link[1]]++;
    }
    for (int i=0; i<n; i++) {
        if (indegree[i]==0) {
            root=i;
        }
    }

    //return {sum of subtree with root(now), #subtree}
    function<pair<int, int>(int, int)> sol=[&](int now, int bound) {
        pair<int, int> ret;

        if (links[now][0]!=-1 && links[now][1]!=-1) {
            pair<int, int> tmp0=sol(links[now][0], bound);
            pair<int, int> tmp1=sol(links[now][1], bound);
            if (num[now]+tmp0.first+tmp1.first>bound) {
                if (num[now]+tmp0.first>bound && num[now]+tmp1.first>bound) {
                    ret.first=num[now];
                    ret.second=tmp0.second+tmp1.second+1;
                }
                else if (num[now]+tmp0.first<=bound && num[now]+tmp1.first>bound) {
                    ret.first=num[now]+tmp0.first;
                    ret.second=tmp0.second+tmp1.second;
                }
                else if (num[now]+tmp1.first<=bound && num[now]+tmp0.first>bound) {
                    ret.first=num[now]+tmp1.first;
                    ret.second=tmp0.second+tmp1.second;
                }
                else {
                    if (tmp0.first<tmp1.first) {
                        ret.first=num[now]+tmp0.first;
                        ret.second=tmp0.second+tmp1.second;
                    }
                    else {
                        ret.first=num[now]+tmp1.first;
                        ret.second=tmp0.second+tmp1.second;
                    }
                }
            }
            else {
                ret.first=num[now]+tmp0.first+tmp1.first;
                ret.second=tmp0.second+tmp1.second-1;
            }
        }
        else if (links[now][0]!=-1) {
            pair<int, int> tmp=sol(links[now][0], bound);
            if (num[now]+tmp.first>bound) {
                ret.first=num[now];
                ret.second=tmp.second+1;
            }
            else {
                ret.first=num[now]+tmp.first;
                ret.second=tmp.second;
            }
        }
        else if (links[now][1]!=-1) {
            pair<int, int> tmp=sol(links[now][1], bound);
            if (num[now]+tmp.first>bound) {
                ret.first=num[now];
                ret.second=tmp.second+1;
            }
            else {
                ret.first=num[now]+tmp.first;
                ret.second=tmp.second;
            }
        }
        else {
            ret.first=num[now];
            ret.second=1;
        }

        return ret;
    };

    int sum=0;
    for (auto i:num) sum+=i;
    int left=*max_element(num.begin(), num.end())-1;
    int right=sum+1;
    int ret=INT_MAX;
    while (left+1<right) {
        int mid=(left+right)/2;

        if (sol(root, mid).second<=k) {
            ret=mid;
            right=mid;
        }
        else {
            left=mid;
        }
    }

    return ret;
}