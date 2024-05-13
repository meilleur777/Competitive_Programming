#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    //src 0, dst 1, person 2~n+1, bookstore n+2~n+m+1
    int siz=n+m+2;
    int src=0, dst=1;
    vector<vector<int>> edge(siz);
    vector<vector<int>> flow(siz, vector<int>(siz, 0));
    vector<vector<int>> capacity(siz, vector<int>(siz, 0));

    //src to person
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        edge[src].push_back(i+2);
        edge[i+2].push_back(src);
        capacity[src][i+2]=a;
    }
    //bookstore to dst
    for (int i=0; i<m; i++) {
        int b;
        cin >> b;
        edge[n+2+i].push_back(dst);
        edge[dst].push_back(n+2+i);
        capacity[n+2+i][dst]=b;
    }
    //person to bookstore
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            int c;
            cin >> c;
            edge[j+2].push_back(n+2+i);
            edge[n+2+i].push_back(j+2);
            capacity[j+2][n+2+i]=c;
        }
    }

    int ans=0;
    while (true) {
        queue<int> q;
        q.push(src);

        vector<int> parent(siz, -1);

        while (!q.empty()) {
            int now=q.front();
            q.pop();

            for (auto nxt:edge[now]) {
                if (capacity[now][nxt]-flow[now][nxt]>0 && parent[nxt]==-1) {
                    q.push(nxt);
                    parent[nxt]=now;
                }
            }
        }

        if (parent[dst]==-1) break;

        int mn=0x3f3f3f3f;
        for (int now=dst; now!=src; now=parent[now]) {
            mn=min(mn, capacity[parent[now]][now]-flow[parent[now]][now]);
        }
        for (int now=dst; now!=src; now=parent[now]) {
            flow[parent[now]][now]+=mn;
            flow[now][parent[now]]-=mn;
        }

        ans+=mn;
    }

    cout << ans;

    return 0;
}
