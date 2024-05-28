#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];

    vector<int> cnt(1e4+1, 0);
    for (auto i:v) cnt[i]++;

    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a==1) {
            if (b==0) {
                cout << (cnt[0]!=0 && n>=2) << '\n';
            }
            else {
                bool flag=false;
                for (int i=1; i*i<=b && i<=1e4; i++) {
                    if (cnt[i]>=1) {
                        cnt[i]--;
                        if (b%i==0 && b/i<=1e4 && cnt[b/i]>=1) {
                            flag=true;
                        }
                        cnt[i]++;
                    }
                }
                cout << flag << '\n';
            }
        }
        else {
            cnt[v[b-1]]--;
            v[b-1]=0;
            cnt[v[b-1]]++;
        }
    }

    return 0;
}
