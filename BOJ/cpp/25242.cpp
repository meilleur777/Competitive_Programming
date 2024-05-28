#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    const int inf=0x3f3f3f3f;

    int n, query;
    cin >> n >> query;
    map<string, int> nameToNum;
    set<string> cross;
    vector<vector<string>> route(n);
    for (int i=0; i<n; i++) {
        int routeLen;
        cin >> routeLen;
        route[i]=vector<string>(routeLen);

        for (int j=0; j<routeLen; j++) {
            cin >> route[i][j];

            if (nameToNum.find(route[i][j])==nameToNum.end()) nameToNum[route[i][j]]=nameToNum.size();
            else cross.insert(route[i][j]);
        }
    }

    int nodeNum=nameToNum.size();
    vector<vector<int>> edge(nodeNum);
    vector<pair<int, int>> nodeInfo(nodeNum);
    for (int i=0; i<n; i++) {
        int m=route[i].size();
        for (int j=0; j<m-1; j++) {
            int now=nameToNum[route[i][j]];
            int nxt=nameToNum[route[i][j+1]];
            edge[now].push_back(nxt);
            edge[nxt].push_back(now);
        }

        for (int j=0; j<m; j++) {
            nodeInfo[nameToNum[route[i][j]]]={i, j};
        }
    }

    map<string, int> crossToNum;
    int crossSize=cross.size();
    for (auto i:cross) {
        crossToNum[i]=crossToNum.size();
    }

    //BFS from all cross to every node
    vector<vector<int>> dist(crossSize, vector<int>(nodeNum, inf));
    for (auto start:cross) {
        queue<int> q;
        q.push(nameToNum[start]);
        dist[crossToNum[start]][nameToNum[start]]=0;

        while (!q.empty()) {
            int now=q.front();
            q.pop();

            for (auto nxt:edge[now]) {
                if (dist[crossToNum[start]][nxt]==inf) {
                    dist[crossToNum[start]][nxt]=dist[crossToNum[start]][now]+2;
                    q.push(nxt);
                }
            }
        }
    }

    while (query--) {
        string sStr, eStr;
        cin >> sStr >> eStr;
        int src=nameToNum[sStr], dst=nameToNum[eStr];

        int ans=inf;
        for (int pivot=0; pivot<crossSize; pivot++) {
            ans=min(ans, dist[pivot][src]+dist[pivot][dst]);
        }
        if (nodeInfo[src].first==nodeInfo[dst].first) {
            ans=min(ans, (int)abs(nodeInfo[src].second-nodeInfo[dst].second)*2);
        }

        if (ans==inf) cout << -1 << '\n';
        else cout << ans << '\n';
    }

    return 0;
}
