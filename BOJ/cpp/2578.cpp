#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
            
    vector<vector<int>> v(5, vector<int>(5));
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cin >> v[i][j];
        }
    }

    bool endflag=false;

    for (int k=0; k<25; k++) {

        int a;
        cin >> a;
        if (endflag) continue;

        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                if (v[i][j]==a) v[i][j]=0;
            }
        }

        int cnt=0;
        bool flag=false;

        for (int i=0; i<5; i++) {
            flag=true;
            for (int j=0; j<5; j++) {
                if (v[i][j]) flag=false;
            }
            cnt+=flag;
        }

        for (int i=0; i<5; i++) {
            flag=true;
            for (int j=0; j<5; j++) {
                if (v[j][i]) flag=false;
            }
            cnt+=flag;
        }

        flag=true;
        for (int i=0; i<5; i++) {   
            if (v[i][i]) flag=false;
        }
        cnt+=flag;

        flag=true;
        for (int i=0; i<5; i++) {
            if (v[i][4-i]) flag=false;
        }
        cnt+=flag;

        if (cnt>=3) {
            endflag=true;
            cout << k+1;
        }
    }

    return 0;
}
