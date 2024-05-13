#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;
    vector<vector<int>> edge(n);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
    }

    int num=0;
    stack<int> sk;
    map<int, int> sccSize;
    vector<int> sccTag(n);
    vector<int> tag(n, -1);
    vector<bool> fin(n, false);
    int sccNum=0;

    function<int(int)> tarjan=[&](int now) {
        tag[now]=num;
        num++;
        sk.push(now);
        int par=tag[now];

        for (auto nxt:edge[now]) {
            if (tag[nxt]==-1) {
                par=min(par, tarjan(nxt));
            }
            else if (fin[nxt]==false) {
                par=min(par, tag[nxt]);
            }
        }

        if (par==tag[now]) {
            int tmp=-1;
            while (tmp!=now) {
                tmp=sk.top();
                sk.pop();
                fin[tmp]=true;

                sccSize[sccNum]++;
                sccTag[tmp]=sccNum;
            }
            sccNum++;
        }

        return par;
    };

    for (int i=0; i<n; i++) {
        if (!fin[i]) {
            tarjan(i);
        }
    };

    vector<set<int>> newEdge(sccNum);
    for (int now=0; now<n; now++) {
        for (auto nxt:edge[now]) {
            if (sccTag[now]==sccTag[nxt]) continue;
            newEdge[sccTag[now]].insert(sccTag[nxt]);
        }
    }

    const int minusInf=-0x3f3f3f3f;
    vector<int> cache(sccNum, minusInf);
    function<int(int)> dp=[&](int nowScc) {
        if (nowScc==sccTag[t]) {
            return sccSize[nowScc];
        }

        int& ret=cache[nowScc];
        if (ret!=minusInf) return ret;

        for (auto nxt:newEdge[nowScc]) {
            ret=max(ret, dp(nxt)+sccSize[nowScc]);
        }

        return ret;
    };
    cout << max(0, dp(sccTag[s]));

    return 0;
}
