#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    long long sy, sx, ey, ex;
    cin >> sy >> sx >> ey >> ex;
    vector<vector<long long>> v(3, vector<long long>(4));
    for (int i=0; i<3; i++) {
        for (int j=0; j<4; j++) {
            cin >> v[i][j];
        }
    }

    map<pair<long long, long long>, int> mp;
    mp[{sy, sx}]=0;
    mp[{ey, ex}]=1;
    int num=2;
    for (int i=0; i<3; i++) {
        for (int j=0; j<2; j++) {
            if (mp.find({v[i][j*2], v[i][j*2+1]})==mp.end()) {
                mp[{v[i][j*2], v[i][j*2+1]}]=num;
                num++;
            }
        }
    }

    const long long inf=0x3f3f3f3f3f3f3f3f;
    vector<vector<long long>> dist(num, vector<long long>(num, inf));
    for (auto [p, from]:mp) {
        for (auto [q, to]:mp) {
            long long tmp=llabs(p.first-q.first)+llabs(p.second-q.second);
            dist[from][to]=min(dist[from][to], tmp);
        }
    }

    for (int i=0; i<3; i++) {
        for (int j=0; j<2; j++) {
            dist[mp[{v[i][0], v[i][1]}]][mp[{v[i][2], v[i][3]}]]=
            min(dist[mp[{v[i][0], v[i][1]}]][mp[{v[i][2], v[i][3]}]], 10LL);

            dist[mp[{v[i][2], v[i][3]}]][mp[{v[i][0], v[i][1]}]]=
            min(dist[mp[{v[i][2], v[i][3]}]][mp[{v[i][0], v[i][1]}]], 10LL);
        }
    }

    for (int pivot=0; pivot<num; pivot++) {
        for (int i=0; i<num; i++) {
            for (int j=0; j<num; j++) {
                dist[i][j]=min(dist[i][j], dist[i][pivot]+dist[pivot][j]);
            }
        }
    }

    cout << dist[0][1];

    return 0;
}
