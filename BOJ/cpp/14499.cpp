#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m, k;
    pair<int, int> s;
    cin >> n >> m >> s.first >> s.second >> k;
    vector<vector<int>> brd(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> brd[i][j];
        }
    }

    vector<map<int, int>> v(4);
    v[0]={{3, 1}, {1, 4}, {4, 6}, {6, 3}, {2, 2}, {5, 5}};
    v[1]={{1, 3}, {4, 1}, {6, 4}, {3, 6}, {2, 2}, {5, 5}};
    v[2]={{6, 2}, {2, 1}, {1, 5}, {5, 6}, {4, 4}, {3, 3}};
    v[3]={{2, 6}, {1, 2}, {5, 1}, {6, 5}, {4, 4}, {3, 3}};

    vector<int> dice(7, 0);
    vector<int> dy({0, 0, -1, 1});
    vector<int> dx({1, -1, 0, 0});
    pair<int, int> pos=s;
    while (k--) {
        int ist;
        cin >> ist;

        auto [y, x]=pos;
        int ty=y+dy[ist-1];
        int tx=x+dx[ist-1];
        if (ty>=n || ty<0 || tx>=m || tx<0) continue;
        pos={ty, tx};

        vector<int> tdice(7, 0);
        for (int i=1; i<=6; i++) {
            tdice[v[ist-1][i]]=dice[i];
        }
        dice=tdice;

        if (brd[ty][tx]==0) {
            brd[ty][tx]=dice[6];
        }
        else {
            dice[6]=brd[ty][tx];
            brd[ty][tx]=0;
        }
        cout << dice[1] << '\n';
    }

    return 0;
}
