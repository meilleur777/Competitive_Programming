#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> edge[16][16];
int capacity[16][16][16][16]={0};
int flow[16][16][16][16]={0};
int weight[16][16][16][16]={0};
vector<int> dy({0, 0, 1, -1});
vector<int> dx({1, -1, 0, 0});

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<string> brd(n);
    for (int i=0; i<n; i++) cin >> brd[i];
    map<string, int> score;
    vector<int> scoreBrd({10, 8, 7, 5, 1, 8, 6, 4, 3, 1, 7, 4, 3, 2, 1, 5, 3, 2, 2, 1, 1, 1, 1, 1, 0});
    string alp="ABCDF";
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            score[string({alp[i], alp[j]})]=scoreBrd[i*5+j];
        }
    }

    pair<int, int> src={n, 0}, dst={n, 1};

    for (int i=0; i<n; i++) {
        for (int j=(i%2==1); j<m; j+=2) {
            edge[src.first][src.second].push_back({i, j});
            edge[i][j].push_back(src);
            capacity[src.first][src.second][i][j]=1;

            edge[i][j].push_back(dst);
            edge[dst.first][dst.second].push_back({i, j});
            capacity[i][j][dst.first][dst.second]=1;

            for (int d=0; d<4; d++) {
                int ny=i+dy[d];
                int nx=j+dx[d];
                if (ny>=n || ny<0 || nx>=m || nx<0) continue;

                edge[i][j].push_back({ny, nx});
                edge[ny][nx].push_back({i, j});
                capacity[i][j][ny][nx]=1;
                weight[i][j][ny][nx]=-score[string({brd[i][j], brd[ny][nx]})];
                weight[ny][nx][i][j]=score[string({brd[i][j], brd[ny][nx]})];
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=(i%2==0); j<m; j+=2) {
            edge[i][j].push_back(dst);
            edge[dst.first][dst.second].push_back({i, j});
            capacity[i][j][dst.first][dst.second]=1;
        }
    }   

    //Shortest Path Faster algorithm
    int totalCost=0;
    const int inf=0x3f3f3f3f;
    pair<int, int> empty={-1, -1};
    while (true) {
        queue<pair<int, int>> q;
        vector<vector<int>> dist(n+1, vector<int>(m+1, inf));
        vector<vector<bool>> inQ(n+1, vector<bool>(m+1, false));
        vector<vector<pair<int, int>>> par(n+1, vector<pair<int, int>>(m+1, empty));

        q.push(src);
        dist[src.first][src.second]=0;
        inQ[src.first][src.second]=true;

        while (!q.empty()) {
            auto [y, x]=q.front();
            q.pop();
            inQ[y][x]=false;

            for (auto [ny, nx]:edge[y][x]) {
                if (capacity[y][x][ny][nx]-flow[y][x][ny][nx]>0 && 
                    dist[ny][nx]>dist[y][x]+weight[y][x][ny][nx]) {
                    dist[ny][nx]=dist[y][x]+weight[y][x][ny][nx];
                    par[ny][nx]={y, x};
                    if (!inQ[ny][nx]) {
                        inQ[ny][nx]=true;
                        q.push({ny, nx});
                    }
                }
            }
        }

        if (par[dst.first][dst.second]==empty) break;

        int newFlow=inf;
        for (auto nxt=dst; nxt!=src; nxt=par[nxt.first][nxt.second]) {
            auto now=par[nxt.first][nxt.second];
            newFlow=min(newFlow, capacity[now.first][now.second][nxt.first][nxt.second]-
                                 flow[now.first][now.second][nxt.first][nxt.second]);
        }
        for (auto nxt=dst; nxt!=src; nxt=par[nxt.first][nxt.second]) {
            auto now=par[nxt.first][nxt.second];
            flow[now.first][now.second][nxt.first][nxt.second]+=newFlow;
            flow[nxt.first][nxt.second][now.first][now.second]-=newFlow;
            totalCost+=newFlow*weight[now.first][now.second][nxt.first][nxt.second];
        }
    }

    cout << -totalCost;

    return 0;
}
