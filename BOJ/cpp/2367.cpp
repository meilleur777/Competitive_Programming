#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, k, d;
    cin >> n >> k >> d;

    //src 0, dst 1, person 2~n+1, food n+2~n+d+1
    int siz=n+d+2;
    int src=0, dst=1;
    vector<vector<int>> edge(siz);
    vector<vector<int>> capacity(siz, vector<int>(siz, 0));
    vector<vector<int>> flow(siz, vector<int>(siz, 0));

    //src to person
    for (int i=0; i<n; i++) {
        edge[0].push_back(2+i);
        edge[2+i].push_back(0);
        capacity[0][2+i]=k;
    }
    //food to dst
    for (int i=0; i<d; i++) {
        int a;
        cin >> a;
        edge[n+2+i].push_back(dst);
        edge[dst].push_back(n+2+i);
        capacity[n+2+i][dst]=a;
    }
    //person to food
    for (int i=0; i<n; i++) {
        int z;
        cin >> z;
        for (int j=0; j<z; j++) {
            int a;
            cin >> a;
            a--;
            edge[i+2].push_back(n+2+a);
            edge[n+2+a].push_back(i+2);
            capacity[i+2][n+2+a]=1;
        }
    }

    //Edmonds-Karp algorithm
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
                    if (nxt==dst) break;
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
