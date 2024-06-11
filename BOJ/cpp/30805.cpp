#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (int i=0; i<m; i++) cin >> b[i];

    vector<int> ansv;
    int aa=0, bb=0;
    for (int i=100; i>=1; i--) {
        while (true) {
            if (aa>=n || bb>=m) break;

            int taa=-1, tbb=-1;
            for (int j=aa; j<n; j++) {
                if (a[j]==i) {
                    taa=j;
                    break;
                }
            }
            for (int j=bb; j<m; j++) {
                if (b[j]==i) {
                    tbb=j;
                    break;
                }
            }

            if (taa==-1 || tbb==-1) break;

            ansv.push_back(i);
            aa=taa+1, bb=tbb+1;
        }
    }

    cout << (int)ansv.size() << '\n';
    for (auto i:ansv) cout << i << ' ';

    return 0;
}
