#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    //src=0, dst=1, column sum=2~n+1, row sum=n+2~n*2+1
    int src=0, dst=1;
    int siz=n*2+2;
    const int inf=0x3f3f3f3f;
    vector<vector<int>> edge(siz);
    vector<vector<int>> flow;
    vector<vector<int>> capacity(siz, vector<int>(siz, 0));
    int mxFlow=0;
    for (int i=0; i<n; i++) {
        edge[src].push_back(2+i);
        edge[2+i].push_back(src);
        cin >> capacity[src][2+i];
        mxFlow+=capacity[src][2+i];
    }
    for (int i=0; i<n; i++) {
        edge[n+2+i].push_back(dst);
        edge[dst].push_back(n+2+i);
        cin >> capacity[n+2+i][dst];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            edge[2+i].push_back(n+2+j);
            edge[n+2+j].push_back(2+i);
        }
    }

    int mnPoss=1e4;
    int left=-1, right=1e4+1;
    vector<vector<int>> resBrd;
    while (left+1<right) {
        int mid=(left+right)/2;

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                capacity[2+i][n+2+j]=mid;
            }
        }
        flow=vector<vector<int>>(siz, vector<int>(siz, 0));

        //Edmonds-karp algorithm
        int resFlow=0;
        while (true) {
            queue<int> q;
            q.push(src);
            vector<int> par(siz, -1);

            while (!q.empty())  {
                int now=q.front();
                q.pop();

                for (auto nxt:edge[now]) {
                    if (capacity[now][nxt]-flow[now][nxt]>0 && par[nxt]==-1) {
                        q.push(nxt);
                        par[nxt]=now;
                    }
                }
            }

            if (par[dst]==-1) break;

            int mnFlow=inf;
            for (int nxt=dst; nxt!=src; nxt=par[nxt]) {
                int now=par[nxt];
                mnFlow=min(mnFlow, capacity[now][nxt]-flow[now][nxt]);
            }
            for (int nxt=dst; nxt!=src; nxt=par[nxt]) {
                int now=par[nxt];
                flow[now][nxt]+=mnFlow;
                flow[nxt][now]-=mnFlow;
            }
            resFlow+=mnFlow;
        }

        if (resFlow==mxFlow) {
            right=mid;
            mnPoss=mid;
            resBrd=flow;
        }
        else left=mid;
    }

    cout << mnPoss << '\n';
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << resBrd[2+i][n+2+j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
