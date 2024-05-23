#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> brd, vector<string> opes) {
    string dirChar="NSWE";
    vector<int> dy({-1, 1, 0, 0});
    vector<int> dx({0, 0, -1, 1});
    
    int y, x;
    int n=brd.size(), m=brd.front().size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (brd[i][j]=='S') {
                y=i;
                x=j;
            }
        }
    }

    for (auto ope:opes) {
        int dir=dirChar.find(ope[0]);
        int dist=int(ope[2]-'0');
        
        bool flag=true;
        int ny=y, nx=x;
        while (dist--) {
            ny+=dy[dir];
            nx+=dx[dir];
            if (ny>=n || ny<0 || nx>=m || nx<0) {
                flag=false;
                break;
            }
            if (brd[ny][nx]=='X') {
                flag=false;
                break;
            }
        }
        
        if (flag) {
            y=ny;
            x=nx;
        }
    }
    
    return vector<int>({y, x});
}
