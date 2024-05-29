#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> v(k);
    for (int i=0; i<k; i++) {
        cin >> v[i];
    }

    const int inf=0x3f3f3f3f;
    vector<int> rem(k+1, inf);
    vector<int> nxt(k);
    for (int i=k-1; i>=0; i--) {
        nxt[i]=rem[v[i]];
        rem[v[i]]=i;
    }

    int ans=0;
    vector<int> isIn(k+1, -1);
    for (int i=0; i<k; i++) {
        if (isIn[v[i]]==-1) { 
            int cnt=0;
            int mx=-1;
            for (auto j:isIn) {
                if (j!=-1) {
                    mx=max(mx, j);
                    cnt++;
                }
            }

            if (cnt>=n) {
                for (auto& j:isIn) {
                    if (mx==j) {
                        j=-1;
                        break;
                    }
                }
                isIn[v[i]]=nxt[i];
                ans++;
            }
        }
        isIn[v[i]]=nxt[i];
    }

    cout << ans;

    return 0;
}
