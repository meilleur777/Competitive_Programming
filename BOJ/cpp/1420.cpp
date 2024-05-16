#include <bits/stdc++.h>
using namespace std;

//Max-flow min-cut Theorem
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<string> brd(n);
    for (int i=0; i<n; i++) cin >> brd[i];
    pair<int, int> src, dst;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (brd[i][j]=='K') src={i, j};
            if (brd[i][j]=='H') dst={i, j};
        }
    }

    int srcOut=(src.first*m+src.second)*2+1;
    int dstIn=(dst.first*m+dst.second)*2;

    //for each coordinate {i, j} in brd, assign nodeIn->(i*m+j)*2, nodeOut->(i*m+j)*2+1
    //hence, the range node is 0~((n-1)*m+m-1)*2+1
    int siz=((n-1)*m+m-1)*2+2; //~2e4
    //each nodeIn can be connected to nodeOut, vice versa
    //capacity[d][num]:= d is direction of edge => 0~3->move, 4->nodeIn and nodeOut
    vector<vector<int>> edge(siz, vector<int>(5, -1));
    vector<vector<int>> capacity(5, vector<int>(siz, 0));
    vector<vector<int>> flow(5, vector<int>(siz, 0));

    const int inf=0x3f3f3f3f;
    vector<int> dy({0, 0, 1, -1});
    vector<int> dx({1, -1, 0, 0});
    function<int(int)> inv=[&](int x) {
        switch (x) {
            case 0: return 1;
            case 1: return 0;
            case 2: return 3;
            case 3: return 2;
            case 4: return 4;
        }
        return -1;
    };

    //make edge
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (brd[i][j]=='#') continue;

            for (int k=0; k<2; k++) { //for nodeIn and nodeOut
                int nowNode=(i*m+j)*2+k;

                for (int d=0; d<4; d++) {
                    int ny=i+dy[d];
                    int nx=j+dx[d];
                    if (ny>=n || ny<0 || nx>=m || nx<0) continue;
                    if (brd[ny][nx]=='#') continue;

                    int nxtNode=(ny*m+nx)*2+(1-k);  //nodeIn to nodeOut, nodeOut to nodeIn
                    edge[nowNode][d]=nxtNode;

                    if (k==0) capacity[d][nowNode]=0;
                    else if (k==1) capacity[d][nowNode]=inf;
                }
            }

            int nodeIn=(i*m+j)*2;
            int nodeOut=(i*m+j)*2+1;
            capacity[4][nodeIn]=1;
            capacity[4][nodeOut]=0;
            edge[nodeIn][4]=nodeOut;
            edge[nodeOut][4]=nodeIn;
        }
    }

    int ans=0;
    //Edmonds-karp algorithm
    while (true) {
        queue<int> q;
        q.push(srcOut);

        vector<int> par(siz, -1);

        while (!q.empty()) {
            int now=q.front();
            q.pop();


            for (int d=0; d<5; d++) {
                int nxt=edge[now][d];
                if (nxt==-1) continue;

                if (capacity[d][now]-flow[d][now]>0 && par[nxt]==-1) {
                    par[nxt]=now;
                    q.push(nxt);
                }
            }
        }

        if (par[dstIn]==-1) break;

        int mn=inf;
        for (int nxt=dstIn; nxt!=srcOut; nxt=par[nxt]) {
            int now=par[nxt];
            for (int d=0; d<5; d++) {
                if (edge[now][d]==nxt) {
                    mn=min(mn, capacity[d][now]-flow[d][now]);
                    break;
                }
            }
        }

        for (int nxt=dstIn; nxt!=srcOut; nxt=par[nxt]) {
            int now=par[nxt];
            for (int d=0; d<5; d++) {
                if (edge[now][d]==nxt) {
                    flow[d][now]+=mn;
                    flow[inv(d)][nxt]-=mn;
                }
            }
        }

        ans+=mn;
    }

    if (ans>=inf) cout << -1;
    else cout << ans;

    return 0;
}
