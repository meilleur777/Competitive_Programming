#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int w, h, n;
    cin >> w >> h >> n;
    vector<vector<bool>> painted(w, vector<bool>(h, false));

    for (int i=0; i<n; i++) {
        int x, y, a;
        cin >> x >> y >> a;

        if (a==1) {
            for (int i=0; i<x; i++) {
                for (int j=0; j<h; j++) {
                    painted[i][j]=true;
                }
            }
        }
        else if (a==2) {
            for (int i=x; i<w; i++) {
                for (int j=0; j<h; j++) {
                    painted[i][j]=true;
                }
            }
        }
        else if (a==3) {
            for (int i=0; i<w; i++) {
                for (int j=0; j<y; j++) {
                    painted[i][j]=true;
                }
            }
        }
        else if (a==4)  {
            for (int i=0; i<w; i++) {
                for (int j=y; j<h; j++) {
                    painted[i][j]=true;
                }
            }
        }
    }

    int ans=0;
    for (int i=0; i<w; i++) {
        for (int j=0; j<h; j++) {
            ans+=painted[i][j];
        }
    }
    cout << h*w-ans;

    return 0;
}
