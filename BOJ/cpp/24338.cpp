#include <bits/stdc++.h>
using namespace std;

int height(const char& c) {
    if (c=='.' || c=='P' || c=='B') return 0;
    if (c=='1') return 1;
    return 2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<string> brd(n);
    for (int i=0; i<n; i++) cin >> brd[i];
    int sy, sx;
    cin >> sy >> sx;
    sy--, sx--;

    string rampStr="NESW";
    vector<int> dy({-1, 0, 1, 0});
    vector<int> dx({0, 1, 0, -1});

    int compNum=0;
    vector<vector<int>> comp(n, vector<int>(m, -1));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (height(brd[i][j])>=2) continue;
            if (comp[i][j]!=-1) continue;

            queue<pair<int, int>> q;
            q.push({i, j});
            comp[i][j]=compNum;

            while (!q.empty()) {
                auto [y, x]=q.front();
                q.pop();

                for (int d=0; d<4; d++) {
                    int ny=y+dy[d];
                    int nx=x+dx[d];
                    if (ny>=n || ny<0 || nx>=m || nx<0) continue;
                    if (height(brd[ny][nx])!=height(brd[y][x])) continue;
                    if (comp[ny][nx]!=-1) continue;

                    comp[ny][nx]=compNum;
                    q.push({ny, nx});
                }
            }

            compNum++;
        }
    }

    vector<bool> isEnd(compNum, false);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (brd[i][j]=='P') isEnd[comp[i][j]]=true;
            if (brd[i][j]=='B') isEnd[comp[i][j]]=true;
        }
    }

    vector<pair<pair<int, int>, vector<int>>> rampPos;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (brd[i][j]!='?') continue;

            vector<int> candidate;
            for (int d=0; d<4; d++) {
                int ny=i+dy[d];
                int nx=j+dx[d];
                int py=i-dy[d];
                int px=j-dx[d];

                if (ny>=n || ny<0 || nx>=m || nx<0) continue;
                if (py>=n || py<0 || px>=m || px<0) continue;

                if (height(brd[py][px])==0 && height(brd[ny][nx])==1) {
                    candidate.push_back(d);
                }
            }

            if (candidate.empty()) brd[i][j]='N';
            else {
                if ((int)candidate.size()==1) candidate.push_back(candidate[0]);
                rampPos.push_back({{i, j}, candidate});
            }
        }
    }

    bool flag=false;
    int k=rampPos.size();
    for (int i=0; i<(1<<k); i++) {
        map<int, vector<int>> edge;
        for (int j=0; j<k; j++) {
            int jIni;
            if ((i&(1<<j))) jIni=1;
            else jIni=0;
            auto [y, x]=rampPos[j].first;
            int d=rampPos[j].second[jIni];

            brd[y][x]=rampStr[d];
            int ny=y+dy[d];
            int nx=x+dx[d];
            int py=y-dy[d];
            int px=x-dx[d];
            edge[comp[py][px]].push_back(comp[ny][nx]);
            edge[comp[ny][nx]].push_back(comp[py][px]);
        }

        queue<int> q;
        q.push(comp[sy][sx]);
        vector<bool> vis(compNum, false);
        vis[comp[sy][sx]]=true;
        
        while (!q.empty()) {
            int now=q.front();
            q.pop();

            if (isEnd[now]) {
                flag=true;
                break;
            }

            for (auto nxt:edge[now]) {
                if (vis[nxt]) continue;
                vis[nxt]=true;
                q.push(nxt);
            }
        }

        if (flag==true) break;
    }

    if (flag) for (auto s:brd) cout << s << '\n';
    else cout << -1;

    return 0;
}
