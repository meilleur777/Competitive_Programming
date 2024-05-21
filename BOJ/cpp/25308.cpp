#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    vector<long long> a(8);
    for (int i=0; i<8; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<int> p(8);
    for (int i=0; i<8; i++) p[i]=i;

    int ans=0;
    do {
        vector<long long> b(8);
        for (int i=0; i<8; i++) {
            b[i]=a[p[i]];
        }

        bool flag=true;
        for (int i=0; i<8; i++) {
            if (2*(b[i]*(b[(i+2)%8]))*(b[i]*(b[(i+2)%8])) >    
                (b[(i+2)%8]+b[i])*(b[(i+2)%8]+b[i])*b[(i+1)%8]*b[(i+1)%8]) {
                flag=false;
            }
        }
        ans+=flag;
    } while (next_permutation(p.begin(), p.end()));
    cout << ans;

    return 0;
}
